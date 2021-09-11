# Legacy Code Examples

The directory _examples_, which is the same directory containing this document, contains the top-level 
_CMakeLists.txt_. This _CMakeLists.txt_ has a list of `add_subdirectory` commands with the example projects at its end. 
Uncomment those examples that you are interested in and comment out those that you are not interested in. 

Some examples like _incompatible-c-cpp_ do not build. Comment out these examples if you want to run other examples.

You build all examples from the command line with the following commands:

    $ cd examples
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build . --target all -- -j 6

The above commands use the default C and C++ compilers and the default Makefile generator of your system. If you need
different build settings, pass the appropriate CMake variables and options to the `cmake` calls. You run the tests
with CTest.

    $ ctest -V

Of course, you can load the top-level _CMakeLists.txt_ in your favourite IDE (e.g., QtCreator, VSCode, CLion), and 
build and run the test projects from the IDE.