[![Build status](https://ci.appveyor.com/api/projects/status/jjat3qng2arpmid2/branch/master?svg=true)](https://ci.appveyor.com/project/D3PSI/framerat/branch/master)
![Windows C/C++ CI](https://github.com/D3PSI/framerat/workflows/Windows%20C/C++%20CI/badge.svg)
![Linux C/C++ CI](https://github.com/D3PSI/framerat/workflows/Linux%20C/C++%20CI/badge.svg)
![macOS C/C++ CI](https://github.com/D3PSI/framerat/workflows/macOS%20C/C++%20CI/badge.svg)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/D3PSI/framerat/graphs/commit-activity)
[![GitHub issues](https://img.shields.io/github/issues/D3PSI/framerat.svg)](https://github.com/D3PSI/framerat/issues/)
[![GitHub issues-closed](https://img.shields.io/github/issues-closed/D3PSI/framerat.svg)](https://github.com/D3PSI/framerat/issues?q=is%3Aissue+is%3Aclosed)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](https://github.com/D3PSI/framerat/compare)
[![GitHub pull-requests](https://img.shields.io/github/issues-pr/D3PSI/framerat.svg)](https://GitHub.com/D3PSI/framerat/pull/)
[![GitHub pull-requests closed](https://img.shields.io/github/issues-pr-closed/D3PSI/framerat.svg)](https://GitHub.com/D3PSI/framerat/pull/)
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)

# framerat
The Game Engine Project

![Framerat Logo](https://github.com/D3PSI/framerat/blob/master/res/logo/framerat-logo.png)

# Installation

## Dependencies

You must have the Vulkan SDK installed and added to your PATH environment variable on Windows and macOS systems for the installation process to work. CMake will not find Vulkan otherwise.

The project further depends on libraries like ASSIMP, GLFW, GLM, irrklang and IMGUI, which are installed through your systems package manager if possible or compiled with the project itself. They are mostly included in the repository as a submodule, making dependency management really easy. The project is thus fully cross-platform (at least amongst the platforms that support the API's)

## Linux

The project comes with an install script for Linux systems. It offers support for Debian, Fedora and Arch/Manjaro. Download and run the installer:

    git clone https://github.com/D3PSI/framerat.git
    cd framerat/
    bash install-framerat.sh

## Windows

Generate the Visual Studio build files with CMake. Download and install the CMake GUI from [their official website](cmake.org/download). Clone the repository and initialize all submodules by cloning the repository recursively:

    git clone --recursive https://github.com/D3PSI/framerat.git

Then generate the Visual Studio build files, either via the command line:

    cmake -G "Visual Studio 16 2019" -S framerat/ -B framerat/build

or the GUI by specifying the project root directory as the source directory and the `build/` folder in the project root directory as the output directory. Click configure and then generate. If there are any errors, make sure you have all the [dependencies](#dependencies) installed correctly.

Open the generated Visual Studio solution file in Microsoft Visual Studio, change the configuration to Release and the architecture to x64. You should now be able to build and run the examples which can be found in `build/bin/`.

## macOS

For macOS you can also run the integrated installer from the repository after cloning, just like the [Linux installation instructions](#linux) say:

    git clone https://github.com/D3PSI/framerat.git
    cd framerat/
    bash install-framerat.sh

### Linking the library

To use the library in your own C++ project is really simple: The only file you have to manually include in your sourcecode is `#include <framerat/framerat.hpp>`. Put the either self-compiled or pre-compiled binary library file (Windows: `framerat.lib`, Linux: `libframerat.a`) in the same folder as your `CMakeLists.txt`. In your `CMakeLists.txt` link against the `framerat` library target and include the necessary include directories (the `include`-subfolder of the repository):

    include_directories("path/to/include")
    target_link_libraries(myProject framerat)

## Troubleshoot

In the worst case scenario, the compilation of the entire project takes about 20 to 30 minutes on a single thread (view continuous integration services for more information). To accelerate the process you can run the compilation on multiple threads:

    make -j<number_of_threads>

where `<number_of_threads>` is at max the amount of supported threads of your CPU. This depends strongly on the manufacturer, whether hyperthreading is supported and other factors. Usually a good number to start is to just input the value 4 as this is supported on a wide variety of systems.
