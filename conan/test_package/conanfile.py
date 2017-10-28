from conans import ConanFile, CMake
import os

class OutcomeTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    
#    def requirements(self):
#        if self.settings.compiler == "clang" and float(str(self.settings.compiler.version)) < 4.0:
#            raise Exception("clang >= 4.0 is required, %s is being used" % self.settings.compiler.version)
#        if self.settings.compiler == "gcc" and float(str(self.settings.compiler.version)) < 5.0:
#            raise Exception("GCC >= 5.0 is required, %s is being used" % self.settings.compiler.version)
#        if self.settings.compiler == "Visual Studio" and float(str(self.settings.compiler.version)) < 15:
#            raise Exception("Visual Studio >= 15 is required, %s is being used" % self.settings.compiler.version)

    def build(self):
        cmake = CMake(self)
        # Current dir is "test_package/build/<build_id>" and CMakeLists.txt is in "test_package"
        cmake.configure(source_dir=self.conanfile_directory, build_dir="./")
        cmake.build()

    def test(self):
        os.chdir("bin")
        self.run(".%sexample" % os.sep)
