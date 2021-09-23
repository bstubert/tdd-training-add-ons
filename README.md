# Add-Ons for Using TDD on Legacy Code

James W. Grenning provides a process [how to get legacy C code into a test harness](https://wingman-sw.com/articles/tdd-legacy-c). This process is also known as the [crash-to-pass algorithm](http://blog.wingman-sw.com/archives/27). In this repository, you'll find add-ons like tools, examples and tips how to make this process smoother. These add-ons come from the [legacy code workshops](https://wingman-sw.com/workshops/legacy-code) James and I are running.

Many add-ons should also be useful for writing new code with TDD, that is, for test-driving code. As described, the process is geared towards C code. The post [TDD How-To: Get Your legacy C into a Test Harness](https://wingman-sw.com/articles/tdd-legacy-c) gives a list of common problems and their solutions for legacy C code. My goal is to provide a similar list for C++, Qt and QML.

The prerequisite to use the add-ons is to clone the repository, say, to `/path/to/tdd-training-add-ons`.

    git clone https://github.com/bstubert/tdd-training-add-ons.git

## Getting Started with the First Test

Creating a test file is always the first step in the process of getting legacy code under test. This repository provides setup scripts to generate the test file and the CMake files to build and run the first tests. The setup scripts and the generated test project should run on Linux, macOS and Windows.

### Setup for GoogleTest

You want to install the test project in the directory `/path/to/project/module-1/tests`. You call the setup script for GoogleTest as follows:

    /path/to/tdd-training-add-ons/starter-kits/googletest/setup-googletest /path/to/project/module-1/tests

The script generates the following subtree:

    /path/to/project/module-1/tests/
        CMakeLists.txt
        my_first_test/
            CMakeLists.txt
            my_first_test.cpp

The first `CMakeLists.txt` defines the project `TestContainer`, which adds test projects like `my_first_test` as subdirectories. You add more test projects in this file. 

The second `CMakeLists.txt` defines the project `my_first_test` with the test file `my_first_test.cpp`. You call the function to test from the test function `test1` in `my_first_test.cpp` or you instantiate a class in `test1`. This is the starting point for the crash-to-pass process.

You can build the project `TestContainer` on the command line as follows:

    $ cd /path/to/project/module-1/tests/
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build .

You run tests with CTest in the `build` directory as follows:

    $ ctest -V

With the regular expression `<regex>`, `ctest -V -R <regex>` specifies which test files and test functions to run. 

Of course, you can use your favourite IDE (e.g., QtCreator, VS Code, CLion) to write, build and run the tests.

The web site [Google Test User's Guide](http://google.github.io/googletest/) is the starting point for all things Google Test.

### Setup for QtTest

QtTest requires that you have installed Qt, say, in `/path/to/qt`, which contains the subdirectories `bin`, `include`, `lib` and so on. You best use the same version as for your Qt applications. All Qt5 and Qt6 versions are good enough for testing. You can install Qt with the [online installer](https://download.qt.io/official_releases/qt-installer-framework/4.1.1/), you can build Qt from the source tarball (found [here](https://download.qt.io/official_releases/qt/) and described [here](https://doc.qt.io/qt-5/build-sources.html)) or from the [Git repository](https://wiki.qt.io/Building_Qt_5_from_Git).

You want to install the test project in the directory `/path/to/project/module-1/tests`. You call the setup script for QtTest as follows:

    /path/to/tdd-training-add-ons/starter-kits/qttest/setup-qttest /path/to/project/module-1/tests

The script generates the following subtree:

    /path/to/project/module-1/tests/
        CMakeLists.txt
        MyFirstTest/
            CMakeLists.txt
            MyFirstTest.cpp

The first `CMakeLists.txt` defines the project `TestContainer`, which adds test projects like `MyFirstTest` as subdirectories. You add more test projects in this file. 

The second `CMakeLists.txt` defines the project `MyFirstTest` with the test file `MyFirstTest.cpp`. You call the function to test from the test function `test1` in `MyFirstTest.cpp` or you instantiate a class in `test1`. This is the starting point for the crash-to-pass process.

You can build the project `TestContainer` on the command line as follows:

    $ cd /path/to/project/module-1/tests/
    $ mkdir build
    $ cd build
    $ cmake .. -DCMAKE_PREFIX_PATH=/path/to/qt
    $ cmake --build .

You run tests with CTest in the `build` directory as follows:

    $ ctest -V

With the regular expression `<regex>`, `ctest -V -R <regex>` specifies which test files and test functions to run. 

Of course, you can use your favourite IDE (e.g., QtCreator, VS Code, CLion) to write, build and run the tests.

The web site [Qt Test](https://doc.qt.io/qt-5/qttest-index.html) is the starting point for all things Qt Test.

## Examples

The directory `examples` contains some examples how to deal with problems in legacy code. The file `examples/CMakeLists.txt` has a list of `add_subdirectory` commands for the example projects. Uncomment those examples that you are interested in and comment out those that you are not interested in. Some examples like _incompatible-c-cpp_ do not build. Comment out these examples if you want to run other examples.

You build all examples from the command line with the following commands:

    $ cd examples
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build .

The above commands use the default C and C++ compilers and the default Makefile generator of your system. If you need
different build settings, pass the appropriate CMake variables and options to the `cmake` calls. You run the tests
with CTest.

    $ ctest -V

Of course, you can load `examples/CMakeLists.txt` in your favourite IDE (e.g., QtCreator, VSCode, CLion), and 
build and run the test projects from there.

### Incompatibilites between C and C++

The example `incompatible-c-cpp` is explained in the post [Is the Header Included from extern “C” Compiled as C or C++?](https://embeddeduse.com/2021/09/09/is-the-header-included-from-extern-c-compiled-as-c-or-c/). 
