def gfxrTestWindows(
    String name,
    String buildMode,
    String label,
    String bits,
    String testSuite
) {
    echo "Creating closure for ${name} with label: ${label}"
    return {
        stage(name) {
            echo "About to allocate node with label: ${label}"
            node(label) {
                echo "Running on node: ${env.NODE_NAME} with label requirement: ${label}"

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
                    checkout scm

                    withEnv([
                        "PROJECT_REPO=${scm.userRemoteConfigs.first().url}",
                        "PROJECT_COMMIT=${env.GIT_COMMIT}",
                        "TEST_REPO=git@github.com:LunarG/VulkanTests",
                        "TEST_SUITE_REPO=git@github.com:LunarG/ci-gfxr-suites",
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
                    allowEmptyArchive: false,
                    onlyIfSuccessful: false,
                )
            }
        }
    }
}

def gfxrTestLinux(
    String name,
    String buildMode,
    String label,
    String bits,
    String testSuite
) {
    return {
        stage(name) {
            node(label) {
                echo "Running on node: ${env.NODE_NAME} with label requirement: ${label}"

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
                    checkout scm

                    withEnv([
                        "PROJECT_REPO=${scm.userRemoteConfigs.first().url}",
                        "PROJECT_COMMIT=${env.GIT_COMMIT}",
                        "TEST_REPO=git@github.com:LunarG/VulkanTests",
                        "TEST_SUITE_REPO=git@github.com:LunarG/ci-gfxr-suites",
                        "TEST_SUITE=${testSuite}",
                        "BITS=${bits}",
                        "BUILD_MODE=${buildMode}",
                        "RESULTS_DIR=../vulkantest-results/${name}"
                    ]) {
                        sh './runJob.sh'
                    }
                }

                archiveArtifacts(
                    artifacts: 'vulkantest-results/**',
                    excludes: 'vulkantest-results/**/*.gfxr,vulkantest-results/**/core*,vulkantest-results/**/*.jsonl',
                    allowEmptyArchive: false,
                    onlyIfSuccessful: false,
                )
            }
        }
    }
}

def gfxrTestAndroid(
    String name,
    String buildMode,
    String label,
    String bits,
    String testSuite
) {
    return {
        stage(name) {
            node(label) {
                echo "Running on node: ${env.NODE_NAME} with label requirement: ${label}"

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
                    checkout scm

                    withEnv([
                        "PROJECT_REPO=${scm.userRemoteConfigs.first().url}",
                        "PROJECT_COMMIT=${env.GIT_COMMIT}",
                        "TEST_REPO=git@github.com:LunarG/VulkanTests",
                        "TEST_SUITE_REPO=git@github.com:LunarG/ci-gfxr-suites",
                        "TEST_SUITE=${testSuite}",
                        "BITS=${bits}",
                        "BUILD_MODE=${buildMode}",
                        "RESULTS_DIR=../vulkantest-results/${name}"
                    ]) {
                        sh './runJobAndroid.sh'

                    }
                }

                archiveArtifacts(
                    artifacts: 'vulkantest-results/**',
                    excludes: 'vulkantest-results/**/*.gfxr,vulkantest-results/**/core*,vulkantest-results/**/*.jsonl',
                    allowEmptyArchive: false,
                    onlyIfSuccessful: false,
                )

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

    gfxrTestWindows: this.&gfxrTestWindows,
    gfxrTestLinux: this.&gfxrTestLinux,
    gfxrTestAndroid: this.&gfxrTestAndroid,
]