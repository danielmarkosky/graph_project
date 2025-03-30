from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class DuckDuckConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("boost/1.87.0")
        self.requires("gtest/1.16.0")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()