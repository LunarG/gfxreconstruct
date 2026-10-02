/*
** Copyright (c) 2026 Valve Corporation
** Copyright (c) 2026 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
 */

def cleanWorkSpace() {
    retry(3) {
        try {
            cleanWs(deleteDirs: true)
        } catch (Exception e) {
            sleep(time: 5)
            throw e
        }
    }
    if (isUnix())
        sh 'rm -rf vulkantest-results'
    else
        bat 'if exist vulkantest-results rmdir /s /q vulkantest-results'
}

def gfxrBuildWindows(
    String label,
    def branches,
    List buildModes
) {
    return {
        node(label) {
            try {
                stage('Building GFXR for Windows') {

                    echo "Running on node: ${env.NODE_NAME} with label requirement: ${label}"

                    cleanWorkSpace()

                    dir('gfxreconstruct') {
                        // Use a curated subset of SCM fields: enough to preserve checkout behavior
                        // while avoiding brittle plugin/runtime metadata from the live `scm` object.
                        def scmVars = checkout([
                            $class: 'GitSCM',
                            branches: branches,
                            doGenerateSubmoduleConfigurations: scm.doGenerateSubmoduleConfigurations,
                            extensions: scm.extensions,
                            submoduleCfg: scm.submoduleCfg,
                            userRemoteConfigs: scm.userRemoteConfigs
                        ])

                        withEnv(["TEST_REPO=git@github.com:LunarG/VulkanTests"]) {
                            bat(script: 'ci/cloneTests.bat')
                        }

                        buildModes.each { buildMode ->
                            withEnv([
                                "BITS=64",
                                "BUILD_MODE=${buildMode}",
                                "RESULTS_DIR=../vulkantest-results/Windows-Build-Log-${buildMode}"
                            ]) {
                                bat(script: 'git submodule update --init --recursive --depth 1')
                                bat(script: 'git describe --tags --always')
                                bat(script: 'ci/buildGfxr.bat')
                            }
                            def buildDir = buildMode == 'Debug' ? 'dbuild' : 'build'
                            stash name: "gfxr-windows-${buildMode}",
                                allowEmpty: false,
                                includes: [
                                "${buildDir}/layer/${buildMode}/VkLayer_gfxreconstruct.dll",
                                "${buildDir}/layer/${buildMode}/VkLayer_gfxreconstruct.json",
                                "${buildDir}/layer/d3d12/${buildMode}/d3d12.dll",
                                "${buildDir}/layer/d3d12_capture/${buildMode}/d3d12_capture.dll",
                                "${buildDir}/layer/dxgi/${buildMode}/dxgi.dll",
                                "${buildDir}/tools/compress/${buildMode}/gfxrecon-compress.exe",
                                "${buildDir}/tools/convert/${buildMode}/gfxrecon-convert.exe",
                                "${buildDir}/tools/extract/${buildMode}/gfxrecon-extract.exe",
                                "${buildDir}/tools/info/${buildMode}/gfxrecon-info.exe",
                                "${buildDir}/tools/tocpp/${buildMode}/gfxrecon-tocpp.exe",
                                "${buildDir}/tools/optimize/${buildMode}/gfxrecon-optimize.exe",
                                "${buildDir}/tools/optimize/${buildMode}/dxcompiler.dll",
                                "${buildDir}/tools/optimize/${buildMode}/D3D12/**",
                                "${buildDir}/tools/replay/${buildMode}/gfxrecon-replay.exe",
                                "${buildDir}/tools/replay/${buildMode}/dxcompiler.dll",
                                "${buildDir}/tools/replay/${buildMode}/D3D12/**",
                            ].join(',')

                            // Probably need to stash/archive vulkantest-results for the build
                        }
                    }
                }
            } catch(Exception e) {
                echo "An exception occurred: ${e.message}"
                throw e
            } finally {
                cleanWorkSpace()
            }
        }
    }
}

def gfxrBuildLinux(){}

def gfxrBuildMac(){}

def gfxrBuildAndroid(){}

def gfxrTestWindows(
    String name,
    String buildMode,
    String label,
    String testSuite,
    def branches
) {
    echo "Creating closure for ${name} with label: ${label}"
    return {
        stage(name) {
            echo "About to allocate node with label: ${label}"
            node(label) {
                try {
                    echo "Running on node: ${env.NODE_NAME} with label requirement: ${label}"

                    cleanWorkSpace()

                    dir('gfxreconstruct') {
                        // Use a curated subset of SCM fields: enough to preserve checkout behavior
                        // while avoiding brittle plugin/runtime metadata from the live `scm` object.
                        // Retry to ride out transient network failures during the clone.
                        def scmVars
                        retry(3) {
                            try {
                                scmVars = checkout([
                                    $class: 'GitSCM',
                                    branches: branches,
                                    doGenerateSubmoduleConfigurations: scm.doGenerateSubmoduleConfigurations,
                                    extensions: scm.extensions,
                                    submoduleCfg: scm.submoduleCfg,
                                    userRemoteConfigs: scm.userRemoteConfigs
                                ])
                            } catch (Exception e) {
                                sleep(time: 5)
                                throw e
                            }
                        }
                        def projectCommit = scmVars.GIT_COMMIT ?: env.GIT_COMMIT

                        unstash "gfxr-windows-${buildMode}"

                        catchError(buildResult: 'FAILURE', stageResult: 'FAILURE') {
                            withEnv([
                                "TEST_REPO=git@github.com:LunarG/VulkanTests",
                                "TEST_SUITE_REPO=git@github.com:LunarG/ci-gfxr-suites",
                                "TEST_SUITE=${testSuite}",
                                "BITS=64",
                                "BUILD_MODE=${buildMode}",
                                "RESULTS_DIR=../vulkantest-results/${name}"
                            ]) {
                                bat(script: 'ci/cloneTests.bat')
                                bat(script: 'ci/cloneSuites.bat')
                                bat(script: 'ci/runTest.bat')
                            }
                        }
                    }
                    archiveArtifacts(
                        artifacts: 'python-venv.txt,vulkantest-results/**',
                        excludes: '**/*.gfxr,**/core,**/core.*,**/*.jsonl,**/*.gfxa',
                        allowEmptyArchive: false,
                        onlyIfSuccessful: false,
                    )
                    junit(
                        testResults: 'vulkantest-results/**/*.xml',
                        allowEmptyResults: true,
                        keepLongStdio: true,
                        skipPublishingChecks: true
                    )
                } finally {
                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                        }
                    }
                }
            }
        }
    }
}

def gfxrTestLinux(
    String name,
    String buildMode,
    String label,
    String testSuite,
    def branches
) {
    return {
        stage(name) {
            node(label) {
                try {
                    echo "Running on node: ${env.NODE_NAME} with label requirement: ${label}"

                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                            throw e
                        }
                    }

                    sh 'rm -rf vulkantest-results'

                    dir('gfxreconstruct') {
                        // Use a curated subset of SCM fields: enough to preserve checkout behavior
                        // while avoiding brittle plugin/runtime metadata from the live `scm` object.
                        // Retry to ride out transient network failures during the clone.
                        def scmVars
                        retry(3) {
                            try {
                                scmVars = checkout([
                                    $class: 'GitSCM',
                                    branches: branches,
                                    doGenerateSubmoduleConfigurations: scm.doGenerateSubmoduleConfigurations,
                                    extensions: scm.extensions,
                                    submoduleCfg: scm.submoduleCfg,
                                    userRemoteConfigs: scm.userRemoteConfigs
                                ])
                            } catch (Exception e) {
                                sleep(time: 5)
                                throw e
                            }
                        }
                        def projectCommit = scmVars.GIT_COMMIT ?: env.GIT_COMMIT

                        catchError(buildResult: 'FAILURE', stageResult: 'FAILURE') {
                            withEnv([
                                "PROJECT_REPO=${scm.userRemoteConfigs.first().url}",
                                "PROJECT_COMMIT=${projectCommit}",
                                "TEST_REPO=git@github.com:LunarG/VulkanTests",
                                "TEST_SUITE_REPO=git@github.com:LunarG/ci-gfxr-suites",
                                "TEST_SUITE=${testSuite}",
                                "BITS=64",
                                "BUILD_MODE=${buildMode}",
                                "RESULTS_DIR=../vulkantest-results/${name}"
                            ]) {
                                sh(script: 'git submodule update --init --recursive --depth 1')
                                sh(script: 'git describe --tags --always')
                                sh(script: 'ci/cloneTests.sh')
                                sh(script: 'sh ci/buildGfxr.sh')
                                sh(script: 'ci/cloneSuites.sh')
                                sh(script: 'ci/runTest.sh')
                            }
                        }
                    }
                    archiveArtifacts(
                        artifacts: 'python-venv.txt,vulkantest-results/**',
                        excludes: '**/*.gfxr,**/core,**/core.*,**/*.jsonl,**/*.gfxa',
                        allowEmptyArchive: false,
                        onlyIfSuccessful: false,
                    )
                    junit(
                        testResults: 'vulkantest-results/**/*.xml',
                        allowEmptyResults: true,
                        keepLongStdio: true,
                        skipPublishingChecks: true
                    )
                } finally {
                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                        }
                    }
                }
            }
        }
    }
}

def gfxrTestAndroid(
    String name,
    String buildMode,
    String label,
    String testSuite,
    def branches
) {
    return {
        stage(name) {
            node(label) {
                try {
                    echo "Running on node: ${env.NODE_NAME} with label requirement: ${label}"

                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                            throw e
                        }
                    }

                    sh 'rm -rf vulkantest-results'

                    dir('gfxreconstruct') {
                        // Use a curated subset of SCM fields: enough to preserve checkout behavior
                        // while avoiding brittle plugin/runtime metadata from the live `scm` object.
                        // Retry to ride out transient network failures during the clone.
                        def scmVars
                        retry(3) {
                            try {
                                scmVars = checkout([
                                    $class: 'GitSCM',
                                    branches: branches,
                                    doGenerateSubmoduleConfigurations: scm.doGenerateSubmoduleConfigurations,
                                    extensions: scm.extensions,
                                    submoduleCfg: scm.submoduleCfg,
                                    userRemoteConfigs: scm.userRemoteConfigs
                                ])
                            } catch (Exception e) {
                                sleep(time: 5)
                                throw e
                            }
                        }
                        def projectCommit = scmVars.GIT_COMMIT ?: env.GIT_COMMIT

                        catchError(buildResult: 'FAILURE', stageResult: 'FAILURE') {
                            withEnv([
                                "PROJECT_REPO=${scm.userRemoteConfigs.first().url}",
                                "PROJECT_COMMIT=${projectCommit}",
                                "TEST_REPO=git@github.com:LunarG/VulkanTests",
                                "TEST_SUITE_REPO=git@github.com:LunarG/ci-gfxr-suites",
                                "TEST_SUITE=${testSuite}",
                                "BITS=64",
                                "BUILD_MODE=${buildMode}",
                                "RESULTS_DIR=../vulkantest-results/${name}"
                            ]) {
                                sh(script: 'git submodule update --init --recursive --depth 1')
                                sh(script: 'git describe --tags --always')
                                sh(script: 'ci/cloneTests.sh')
                                sh(script: 'sh ci/buildGfxrAndroid.sh')
                                sh(script: 'ci/cloneSuites.sh')
                                sh(script: 'ci/runTestAndroid.sh')
                            }
                        }
                    }
                    archiveArtifacts(
                        artifacts: 'python-venv.txt,vulkantest-results/**',
                        excludes: '**/*.gfxr,**/core,**/core.*,**/*.jsonl,**/*.gfxa',
                        allowEmptyArchive: false,
                        onlyIfSuccessful: false,
                    )
                    junit(
                        testResults: 'vulkantest-results/**/*.xml',
                        allowEmptyResults: true,
                        keepLongStdio: true,
                        skipPublishingChecks: true
                    )
                } finally {
                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                        }
                    }
                }
            }
        }
    }
}

// Derive job type from node name based on naming convention
def getNodeType(String nodeName) {
    if (nodeName.contains('and')) {
        return 'android'
    } else if (nodeName.contains('wnapl') || nodeName.contains('mac')) {
        return 'linux'
    } else if (nodeName.contains('ubu')) {
        return 'linux'
    } else if (nodeName.contains('win')) {
        return 'windows'
    } else {
        return null
    }
}

def gfxrTestWindowsManual(
    String stageName,
    String nodeLabel,
    String buildMode,
    String bits,
    String testSuite,
    String projectRepo,
    String projectBranch,
    String testRepo,
    String testBranch,
    String testSuiteRepo,
    String testSuiteBranch
) {
    return {
        stage(stageName) {
            node(nodeLabel) {
                try {
                    echo "Running on node: ${env.NODE_NAME} with label requirement: ${nodeLabel}"

                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                            throw e
                        }
                    }

                    bat 'if exist vulkantest-results rmdir /s /q vulkantest-results'

                    dir('gfxreconstruct') {
                        // Retry to ride out transient network failures during the clone.
                        retry(3) {
                            try {
                                checkout([
                                    $class: 'GitSCM',
                                    branches: [[name: projectBranch]],
                                    userRemoteConfigs: [[url: projectRepo]]
                                ])
                            } catch (Exception e) {
                                sleep(time: 5)
                                throw e
                            }
                        }

                        def commitHash = bat(script: '@git rev-parse HEAD', returnStdout: true).trim()

                        catchError(buildResult: 'FAILURE', stageResult: 'FAILURE') {
                            withEnv([
                                "PROJECT_REPO=${projectRepo}",
                                "PROJECT_COMMIT=${commitHash}",
                                "TEST_REPO=${testRepo}",
                                "TEST_BRANCH=${testBranch}",
                                "TEST_SUITE_REPO=${testSuiteRepo}",
                                "TEST_SUITE_BRANCH=${testSuiteBranch}",
                                "TEST_SUITE=${testSuite}",
                                "BITS=${bits}",
                                "BUILD_MODE=${buildMode}",
                                "RESULTS_DIR=../vulkantest-results/${stageName}"
                            ]) {
                                bat(script: 'git submodule update --init --recursive --depth 1')
                                bat(script: 'git describe --tags --always')
                                bat(script: 'ci/cloneTests.bat')
                                bat(script: 'ci/buildGfxr.bat')
                                bat(script: 'ci/cloneSuites.bat')
                                bat(script: 'ci/runTest.bat')
                            }
                        }
                    }
                    archiveArtifacts(
                        artifacts: 'python-venv.txt,vulkantest-results/**',
                        excludes: '**/*.gfxr,**/core,**/core.*,**/*.jsonl,**/*.gfxa',
                        allowEmptyArchive: true,
                        onlyIfSuccessful: false
                    )
                    junit(
                        testResults: 'vulkantest-results/**/*.xml',
                        allowEmptyResults: true,
                        keepLongStdio: true,
                        skipPublishingChecks: true
                    )
                } finally {
                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                        }
                    }
                }
            }
        }
    }
}

def gfxrTestLinuxManual(
    String stageName,
    String nodeLabel,
    String buildMode,
    String bits,
    String testSuite,
    String projectRepo,
    String projectBranch,
    String testRepo,
    String testBranch,
    String testSuiteRepo,
    String testSuiteBranch
) {
    return {
        stage(stageName) {
            node(nodeLabel) {
                try {
                    echo "Running on node: ${env.NODE_NAME} with label requirement: ${nodeLabel}"

                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                            throw e
                        }
                    }

                    sh 'rm -rf vulkantest-results'

                    dir('gfxreconstruct') {
                        // Retry to ride out transient network failures during the clone.
                        retry(3) {
                            try {
                                checkout([
                                    $class: 'GitSCM',
                                    branches: [[name: projectBranch]],
                                    userRemoteConfigs: [[url: projectRepo]]
                                ])
                            } catch (Exception e) {
                                sleep(time: 5)
                                throw e
                            }
                        }

                        def commitHash = sh(script: 'git rev-parse HEAD', returnStdout: true).trim()

                        catchError(buildResult: 'FAILURE', stageResult: 'FAILURE') {
                            withEnv([
                                "PROJECT_REPO=${projectRepo}",
                                "PROJECT_COMMIT=${commitHash}",
                                "TEST_REPO=${testRepo}",
                                "TEST_BRANCH=${testBranch}",
                                "TEST_SUITE_REPO=${testSuiteRepo}",
                                "TEST_SUITE_BRANCH=${testSuiteBranch}",
                                "TEST_SUITE=${testSuite}",
                                "BITS=${bits}",
                                "BUILD_MODE=${buildMode}",
                                "RESULTS_DIR=../vulkantest-results/${stageName}"
                            ]) {
                                sh(script: 'git submodule update --init --recursive --depth 1')
                                sh(script: 'git describe --tags --always')
                                sh(script: 'ci/cloneTests.sh')
                                sh(script: 'sh ci/buildGfxr.sh')
                                sh(script: 'ci/cloneSuites.sh')
                                sh(script: 'ci/runTest.sh')
                            }
                        }
                    }
                    archiveArtifacts(
                        artifacts: 'python-venv.txt,vulkantest-results/**',
                        excludes: '**/*.gfxr,**/core,**/core.*,**/*.jsonl,**/*.gfxa',
                        allowEmptyArchive: true,
                        onlyIfSuccessful: false
                    )
                    junit(
                        testResults: 'vulkantest-results/**/*.xml',
                        allowEmptyResults: true,
                        keepLongStdio: true,
                        skipPublishingChecks: true
                    )
                } finally {
                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                        }
                    }
                }
            }
        }
    }
}

def gfxrTestAndroidManual(
    String stageName,
    String nodeLabel,
    String buildMode,
    String bits,
    String testSuite,
    String projectRepo,
    String projectBranch,
    String testRepo,
    String testBranch,
    String testSuiteRepo,
    String testSuiteBranch
) {
    return {
        stage(stageName) {
            node(nodeLabel) {
                try {
                    echo "Running on node: ${env.NODE_NAME} with label requirement: ${nodeLabel}"

                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                            throw e
                        }
                    }

                    sh 'rm -rf vulkantest-results'

                    dir('gfxreconstruct') {
                        // Retry to ride out transient network failures during the clone.
                        retry(3) {
                            try {
                                checkout([
                                    $class: 'GitSCM',
                                    branches: [[name: projectBranch]],
                                    userRemoteConfigs: [[url: projectRepo]]
                                ])
                            } catch (Exception e) {
                                sleep(time: 5)
                                throw e
                            }
                        }

                        def commitHash = sh(script: 'git rev-parse HEAD', returnStdout: true).trim()

                        catchError(buildResult: 'FAILURE', stageResult: 'FAILURE') {
                            withEnv([
                                "PROJECT_REPO=${projectRepo}",
                                "PROJECT_COMMIT=${commitHash}",
                                "TEST_REPO=${testRepo}",
                                "TEST_BRANCH=${testBranch}",
                                "TEST_SUITE_REPO=${testSuiteRepo}",
                                "TEST_SUITE_BRANCH=${testSuiteBranch}",
                                "TEST_SUITE=${testSuite}",
                                "BITS=${bits}",
                                "BUILD_MODE=${buildMode}",
                                "RESULTS_DIR=../vulkantest-results/${stageName}"
                            ]) {
                                sh(script: 'git submodule update --init --recursive --depth 1')
                                sh(script: 'git describe --tags --always')
                                sh(script: 'ci/cloneTests.sh')
                                sh(script: 'sh ci/buildGfxrAndroid.sh')
                                sh(script: 'ci/cloneSuites.sh')
                                sh(script: 'ci/runTestAndroid.sh')
                            }
                        }
                    }
                    archiveArtifacts(
                        artifacts: 'python-venv.txt,vulkantest-results/**',
                        excludes: '**/*.gfxr,**/core,**/core.*,**/*.jsonl,**/*.gfxa',
                        allowEmptyArchive: true,
                        onlyIfSuccessful: false
                    )
                    junit(
                        testResults: 'vulkantest-results/**/*.xml',
                        allowEmptyResults: true,
                        keepLongStdio: true,
                        skipPublishingChecks: true
                    )
                } finally {
                    retry(3) {
                        try {
                            cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                        } catch (Exception e) {
                            sleep(time: 5)
                        }
                    }
                }
            }
        }
    }
}


return [
    ReleaseMode : 'Release',
    DebugMode : 'Debug',

    LinuxBuildMachineLabel : 'Linux-Build-Machine',
    WindowsBuildMachineLabel : 'Windows-Build-Machine',
    MacBuildMachineLabel : 'Mac-Build-Machine',
    AndroidBuildMachineLabel : 'Android-build-Machine',

    AndroidLabel : 'Linux-Android-GFXR',
    LinuxMesaLabel : 'Linux-Mesa-6800-stable',
    LinuxNvidiaLabel : 'Linux-NVIDIA-950',
    LinuxMesa9070Label : 'Linux-Mesa-9070-stable',
    LinuxNvidia5080Label : 'Linux-NVIDIA-5080',
    MacLabel : 'Mac-M2',
    WinAMDLabel : 'Windows-AMD-6800-64G-RAID',
    WinNvidiaLabel : 'Windows-NVIDIA-20XX-stable',
    Win11ARMLabel : 'Windows11-ARM-GFXR',
    Win11AMD9070Label : 'Windows11-AMD-9070',
    Win11Nvidia50XXLabel : 'Windows11-NVIDIA-50XX',
    WinAMDExtendedLabel: 'Windows-AMD-6800-tcwinamd2',
    WinNvidiaExtendedLabel: 'Windows-NVIDIA-2080-stable-exclusive',

    gfxrBuildWindows: this.&gfxrBuildWindows,
    gfxrBuildLinux: this.&gfxrBuildLinux,
    gfxrBuildMac: this.&gfxrBuildMac,
    gfxrBuildAndroid: this.&gfxrBuildAndroid,

    gfxrTestWindows: this.&gfxrTestWindows,
    gfxrTestLinux: this.&gfxrTestLinux,
    gfxrTestAndroid: this.&gfxrTestAndroid,

    getNodeType: this.&getNodeType,
    gfxrTestWindowsManual: this.&gfxrTestWindowsManual,
    gfxrTestLinuxManual: this.&gfxrTestLinuxManual,
    gfxrTestAndroidManual: this.&gfxrTestAndroidManual,
]
