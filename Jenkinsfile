pipeline {
    agent none

    options {
        disableConcurrentBuilds(abortPrevious: true)
    }

    stages {
        stage('Per Commit Tests') {
            agent none
            steps {
                script {
                    checkout scm

                    def runJob = load 'runJob.groovy'

                    def tests = [
                        'Android Rel64': runJob.gfxrTestAndroid('Android R64', runJob.ReleaseMode, runJob.AndroidLabel, runJob.Bit64, "commit-suite.json"),
                        'Android Dbg64': runJob.gfxrTestAndroid('Android D32', runJob.ReleaseMode, runJob.AndroidLabel, runJob.Bit32, "commit-suite.json"),
                        'Linux Mesa Rel64': runJob.gfxrTestLinux('Linux Mesa Rel64', runJob.ReleaseMode, runJob.LinuxMesaLabel, runJob.Bit64, "commit-suite.json"),
                        'Linux Mesa Dbg32': runJob.gfxrTestLinux('Linux Mesa Dbg32', runJob.ReleaseMode, runJob.LinuxMesaLabel, runJob.Bit32, "commit-suite.json"),
                        'Linux Nnvidia Rel64': runJob.gfxrTestLinux('Linux Nvidia Rel64', runJob.ReleaseMode, runJob.LinuxNvidiaLabel, runJob.Bit64, "commit-suite.json"),
                        'Linux Nnvidia Dbg32': runJob.gfxrTestLinux('Linux Nvidia Dbg32', runJob.ReleaseMode, runJob.LinuxNvidiaLabel, runJob.Bit32, "commit-suite.json"),
                        'Mac': runJob.gfxrTestLinux('Mac', runJob.ReleaseMode, runJob.MacLabel, runJob.Bit64, "commit-suite.json"),
                        'Windows AMD Rel64': runJob.gfxrTestWindows('Windows AMD Rel64', runJob.ReleaseMode, runJob.WinAMDLabel, runJob.Bit64, "commit-suite.json"),
                        'Windows AMD Dbg32': runJob.gfxrTestWindows('Windows AMD Dbg32', runJob.ReleaseMode, runJob.WinAMDLabel, runJob.Bit32, "commit-suite.json"),
                        'Windows Nvidia Rel64': runJob.gfxrTestWindows('Windows Nvidia Rel64', runJob.ReleaseMode, runJob.WinNvidiaLabel, runJob.Bit64, "commit-suite.json"),
                        'Windows Nvidia Dbg32': runJob.gfxrTestWindows('Windows Nvidia Dbg32', runJob.ReleaseMode, runJob.WinNvidiaLabel, runJob.Bit32, "commit-suite.json"),
                        'Windows11 AMD Rel64': runJob.gfxrTestWindows('Windows11 AMD Rel64', runJob.ReleaseMode, runJob.Win11AMDLabel, runJob.Bit64, "commit-suite.json"),
                        'Windows11 AMD Dbg32': runJob.gfxrTestWindows('Windows11 AMD Dbg32', runJob.ReleaseMode, runJob.Win11AMDLabel, runJob.Bit32, "commit-suite.json"),
                        'Windows11 ARM Rel64': runJob.gfxrTestWindows('Windows11 ARM Rel64', runJob.ReleaseMode, runJob.Win11ARMLabel, runJob.Bit64, "commit-suite.json"),
                        'Windows11 ARM Dbg64': runJob.gfxrTestWindows('Windows11 ARM Dbg64', runJob.ReleaseMode, runJob.Win11ARMLabel, runJob.Bit64, "commit-suite.json")
                    ]
                    parallel tests
                }
            }
        }

        stage('Extended Tests') {
            when {
                branch 'dev'
            }

            steps {
                script {
                    checkout scm

                    def runJob = load 'runJob.groovy'

                    def tests = [
                        'Android Rel64': runJob.gfxrTestAndroid('Android R64', runJob.ReleaseMode, runJob.AndroidLabel, runJob.Bit64, "extended-suite.json"),
                        'Linux Mesa Rel64': runJob.gfxrTestLinux('Linux Mesa Rel64', runJob.ReleaseMode, runJob.LinuxMesaLabel, runJob.Bit64, "extended-suite.json"),
                        'Linux Nnvidia Rel64': runJob.gfxrTestLinux('Linux Nvidia Rel64', runJob.ReleaseMode, runJob.LinuxNvidiaLabel, runJob.Bit64, "extended-suite.json"),
                        'Windows AMD Rel64': runJob.gfxrTestWindows('Windows AMD Rel64', runJob.ReleaseMode, runJob.WinAMDLabel, runJob.Bit64, "extended-suite.json"),
                        'Windows Nvidia Rel64': runJob.gfxrTestWindows('Windows Nvidia Rel64', runJob.ReleaseMode, runJob.WinNvidiaLabel, runJob.Bit64, "extended-suite.json"),
                    ]
                    parallel tests
                }
            }
        }
    }

    post {
        always {
            cleanWs()
        }
    }
}