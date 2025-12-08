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
                echo "Running on node: ${env.NODE_NAME} with label requirement: ${nodeLabel}"

                retry(3) {
                    try {
                        cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                    } catch (Exception e) {
                        sleep(time: 5)
                        throw e
                    }
                }

                bat 'if exist vulkantest-results rmdir /s /q vulkantest-results'

                dir('gfxreconstruct') {
                    checkout([
                        $class: 'GitSCM',
                        branches: [[name: projectBranch]],
                        userRemoteConfigs: [[url: projectRepo]]
                    ])

                    def commitHash = bat(script: '@git rev-parse HEAD', returnStdout: true).trim()

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
                        "RESULTS_DIR=../vulkantest-results/${name}"
                    ]) {
                        bat 'runJob.bat'
                    }
                }

                archiveArtifacts(
                    artifacts: 'vulkantest-results/**',
                    excludes: 'vulkantest-results/**/*.gfxr,vulkantest-results/**/core*,vulkantest-results/**/*.jsonl',
                    allowEmptyArchive: true,
                    onlyIfSuccessful: false
                )
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
                echo "Running on node: ${env.NODE_NAME} with label requirement: ${nodeLabel}"

                retry(3) {
                    try {
                        cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                    } catch (Exception e) {
                        sleep(time: 5)
                        throw e
                    }
                }

                sh 'rm -rf vulkantest-results'

                dir('gfxreconstruct') {
                    checkout([
                        $class: 'GitSCM',
                        branches: [[name: projectBranch]],
                        userRemoteConfigs: [[url: projectRepo]]
                    ])

                    def commitHash = sh(script: 'git rev-parse HEAD', returnStdout: true).trim()

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
                        "RESULTS_DIR=../vulkantest-results/${name}"
                    ]) {
                        sh './runJob.sh'
                    }

                    archiveArtifacts(
                        artifacts: 'vulkantest-results/**',
                        excludes: 'vulkantest-results/**/*.gfxr,vulkantest-results/**/core*,vulkantest-results/**/*.jsonl',
                        allowEmptyArchive: true,
                        onlyIfSuccessful: false
                    )
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
                echo "Running on node: ${env.NODE_NAME} with label requirement: ${nodeLabel}"

                retry(3) {
                    try {
                        cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                    } catch (Exception e) {
                        sleep(time: 5)
                        throw e
                    }
                }

                sh 'rm -rf vulkantest-results'

                dir('gfxreconstruct') {
                    checkout([
                        $class: 'GitSCM',
                        branches: [[name: projectBranch]],
                        userRemoteConfigs: [[url: projectRepo]]
                    ])

                    def commitHash = sh(script: 'git rev-parse HEAD', returnStdout: true).trim()

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
                        "RESULTS_DIR=../vulkantest-results/${name}"
                    ]) {
                        sh './runJobAndroid.sh'
                    }

                    archiveArtifacts(
                        artifacts: 'vulkantest-results/**',
                        excludes: 'vulkantest-results/**/*.gfxr,vulkantest-results/**/core*,vulkantest-results/**/*.jsonl',
                        allowEmptyArchive: true,
                        onlyIfSuccessful: false
                    )
                }
            }
        }
    }
}

return [
    Bit64 : '64',
    Bit32 : '32',

    ReleaseMode : 'Release',
    DebugMode : 'Debug',

    AndroidLabel : 'Linux-Android-GFXR',
    LinuxMesaLabel : 'Linux-Mesa-6800-stable',
    LinuxNvidiaLabel : 'Linux-NVIDIA-950',
    MacLabel : 'Mac-M2',
    WinAMDLabel : 'Windows-AMD-6800-64G-RAID',
    WinNvidiaLabel : 'Windows-NVIDIA-20XX-stable',
    Win11AMDLabel : 'Windows11-AMD-6800-stable',
    Win11ARMLabel : 'Windows11-ARM-GFXR',
    WinAMDExtendedLabel: 'Windows-AMD-6800-tcwinamd2',
    WinNvidiaExtendedLabel: 'Windows-NVIDIA-2800-stable-exclusive',

    getNodeType: this.&getNodeType,
    gfxrTestWindowsManual: this.&gfxrTestWindowsManual,
    gfxrTestLinuxManual: this.&gfxrTestLinuxManual,
    gfxrTestAndroidManual: this.&gfxrTestAndroidManual,
]
