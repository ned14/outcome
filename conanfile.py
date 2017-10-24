from conans import ConanFile, CMake
import os


class OutcomeConan(ConanFile):
    name = "outcome"
    version = "master"
    license = "Apache-2.0"
    description = "Provides very lightweight outcome<T> and result<T>"
    url = "https://github.com/ned14/outcome"
    settings = "os", "compiler", "arch", "build_type"
    generators = "cmake"

    @property
    def outcome_src(self):
        return os.path.join(self.source_folder, self.name)

    def source(self):
        self.run("git clone %s --branch %s" % (self.url, self.version))

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_dir=self.outcome_src, build_dir="build")
        cmake.build()
        cmake.test()

    def package(self):
        self.copy("outcome.hpp", dst="include", src=os.path.join("outcome", "single-header"))

    def package_id(self):
        self.info.header_only()
