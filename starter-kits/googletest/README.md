# TDD Starter Kit for Google Test

## How to Build the Starter Kit

We assume that the source code of our project is located in `/our/project/src`. We place our
unit tests in the directory `/our/projects/tests`.

We unpack the googletest-starterkit.zip in a directory of our choice, say, in `/our/downloads`. 
We copy the contents of the subdirectory `google-test/testing-c` to the directory 
`/our/projets/tests`. 

    $ cd /our/projets/tests
    $ cp -r /our/downloads/google-test/testing-c/* /our/projects/tests
    
We can install the starter kit anywhere we want. The closer it is to the source code the easier
it is to provide the paths to the headers, sources and libraries.

The installation above results in the following directory structure under `/our/projects/tests`.

    CMakeLists.txt
    MyFirstUnit
        CMakeLists.txt
        my_first_test_for_first_unit.cpp
        my_second_test_for_first_unit.cpp
    MySecondUnit
        CMakeLists.txt
        my_first_test_for_second_unit.cpp

The tests are grouped by the units under test: `MyFirstUnit` and `MySecondUnit`. Each unit can
contain one or more test files. Each file containes a test suite. If we organise the tests 
differently, we need to adapt the `CMakeLists.txt` fiels.

We build the starter kit with the following commands in `/our/project`. The build downloads 
the Google Test package and builds it. So, the first takes a bit longer. Later builds don't 
rebuild Google Test.

    $ cd /our/project
    $ mkdir build-tests
    $ cmake -S tests -B build-tests -G Ninja -DCMAKE_CXX_COMPILER=/usr/bin/g++ -DCMAKE_C_COMPILER=/usr/bin/gcc
    $ cmake --build build-tests

Depending on the build environment, we must adapt the generator, the C++ compiler and 
the C compiler.

We can run all the tests with `ctest` from the Linux prompt.

    $ cd /our/project/build-tests
    
    // Reports the accumulated results for each test suite of a unit and for the unit itself.
    $ ctest

    // More verbose. Also reports the detailed results for each test.
    $ ctest -V
    
    // Runs the two test suites for unit my_first_unit. The option -R takes regular expressions.
    $ ctest -R my_first_unit -V
    
    // Runs the test suite MyFirstTestForFirstUnit from the first unit.
    $ ctest -R MyFirstTestForFirstUnit -V

The combination of CTest and Google Test integrates well with IDEs like QtCreator and CLion.

## Resources

  - [Quickstart: Building with CMake](http://google.github.io/googletest/quickstart-cmake.html)
  - [Googletest Primer](http://google.github.io/googletest/primer.html)
