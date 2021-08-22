# TDD Starter Kit for Google Test

## How to Build the Starter Kit

We unpack the googletest-starterkit.zip in a directory of our choice. We copy the subdirectory
`testing-c` best to a sibling of the directory containing the source code that we want to test.
For example, if the source directory is `/path/to/unit-1/src`, we run the following two commands:

    $ mkdir /path/to/unit-1/tests
    $ cp -r /path/to/starterkit/google-test/testing-c/* /path/to/unit-1/

We can install the starter kit anywhere we want. The closer it is to the source code the easier
it is to provide the paths to the headers, sources and libraries.

We build the starter kit with the following commands in the subdirectory `build-tests` of 
/path/to/unit-1/tests. This build downloads the Google Test package and builds it. So, the first
takes a bit longer. Later builds don't rebuild Google Test.

    $ cd /path/to/unit-1/tests
    $ mkdir build-tests
    $ cd build-tests
    $ cmake ..
    $ make all -j16

We can run all the tests with `ctest` from the Linux prompt.

    $ cd /path/to/unit-1/tests/build-tests
    
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
