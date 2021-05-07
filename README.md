# A basic demo of Unit Testing in C++ using Google's free [Gtest](https://google.github.io/googletest/)
[![Build Status](https://app.travis-ci.com/refactormyself/basic-gtest.svg?branch=main)](https://app.travis-ci.com/refactormyself/basic-gtest)

The project is testing an my [basic visitor pattern demo](https://github.com/refactormyself/visitor-pattern). I made notes on this pattern [here](www.refactored.live/notes/visitor-pattern-cpp).

No need to install gtest because of the use of Cmake's *FetchContent* feature to clone and setup gtest. The test's CMakeList is isolated in its subdirectory which the top-level adds with `add_subdirectory(test)`, however with this setup it can be a separate project on its own.

The travis setup also builds for *clang* and *gcc* on *amd64* and *arm64*.
#### This Project also illustrates very basic stuffs like
- CMakeList file: [Top-level](./CMakeLists.txt) and [Test with gtest cmake setup](./test/CMakeLists.txt)
- [MakeFile](./Makefile) *(not used)*
- [Travis CI yaml file](./.travis.yml)

### Try it out
Just clone and run this script: `. ./run.sh`   
Nothing fancy, the focus is the pattern and basic tool setup.
