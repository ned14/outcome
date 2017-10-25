from conans import ConanFile, tools

class OutcomeConan(ConanFile):
    name = "Outcome"
    version = "master"
    license = "Apache-2.0"
    description = "Provides very lightweight outcome<T> and result<T>"
    repo_url = "https://github.com/ned14/outcome"
    build_policy = "always"
    
    def build_requirements(self):
        if self.settings.compiler == "clang" and self.settings.compiler.version < "4.0":
            raise ConanException("clang >= 4.0 is required")
        if self.settings.compiler == "gcc" and self.settings.compiler.version < "6.0":
            raise ConanException("GCC >= 6.0 is required")
        if self.settings.compiler == "Visual Studio" and self.settings.compiler.version < "15":
            raise ConanException("Visual Studio >= 15 is required")

    def source(self):
        file_url = "https://raw.githubusercontent.com/ned14/outcome/master/"
        tools.download(file_url + "single-header/outcome.hpp", filename="outcome.hpp")
        tools.download(file_url + "Licence.txt", filename="LICENCE")

    def package(self):
        self.copy("outcome.hpp", dst="include")
        self.copy("LICENCE", dst="licenses")

    def package_id(self):
        self.info.header_only()

    def package_info(self):
        if self.settings.compiler == "clang":
            self.cpp_info.cppflags = "-std=c++14"
            