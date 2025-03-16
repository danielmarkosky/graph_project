from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps

class MyCppProjectConan(ConanFile):
    name = "MyCppProject"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = ["gtest/1.16.0"]
    generators = "CMakeDeps", "CMakeToolchain"

    def layout(self):
        self.folders.source = "."
        self.folders.build = "build"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.bindirs = ["bin"]
