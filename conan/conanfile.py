from conans import ConanFile, tools

class OutcomeConan(ConanFile):
    name = "Outcome"
    version = "master"
    license = "Apache-2.0"
    description = "Provides very lightweight outcome<T> and result<T>"
    repo_url = "https://github.com/ned14/outcome"
    build_policy = "always"

    def source(self):
        file_url = "https://raw.githubusercontent.com/ned14/outcome/master/"
        tools.download(file_url + "single-header/outcome.hpp", filename="outcome.hpp")
        tools.download(file_url + "Licence.txt", filename="LICENCE")

    def package(self):
        self.copy("outcome.hpp", dst="include")
        self.copy("LICENCE", dst="licenses")

    def package_id(self):
        self.info.header_only()
