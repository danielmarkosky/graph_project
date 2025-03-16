from conan import ConanFile

class MySimpleProjectConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
