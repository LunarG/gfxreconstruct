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
    String nodeName,
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
        stage(nodeName) {
            node(nodeName) {
                retry(3) {
                    try {
                        cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                    } catch (Exception e) {
                        sleep(time: 5)
                        throw e
                    }
                }

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
                    ]) {
                        bat 'runJob.bat'

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
}

def gfxrTestLinuxManual(
    String nodeName,
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
        stage(nodeName) {
            node(nodeName) {
                retry(3) {
                    try {
                        cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                    } catch (Exception e) {
                        sleep(time: 5)
                        throw e
                    }
                }

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
                    ]) {
                        sh './runJob.sh'

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
}

def gfxrTestAndroidManual(
    String nodeName,
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
        stage(nodeName) {
            node(nodeName) {
                retry(3) {
                    try {
                        cleanWs(deleteDirs: true, disableDeferredWipeout: true)
                    } catch (Exception e) {
                        sleep(time: 5)
                        throw e
                    }
                }

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
                    ]) {
                        sh './runJobAndroid.sh'

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
}

return [
    getNodeType: this.&getNodeType,
    gfxrTestWindowsManual: this.&gfxrTestWindowsManual,
    gfxrTestLinuxManual: this.&gfxrTestLinuxManual,
    gfxrTestAndroidManual: this.&gfxrTestAndroidManual,
]
