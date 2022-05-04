# A basic command line app demo using the [cli11 library](https://cliutils.github.io/CLI11/)
[![Build Status](https://app.travis-ci.com/refactormyself/basic-cli-util.svg?branch=main)](https://app.travis-ci.com/refactormyself/basic-cli-util)

The project extends the [basic gtest demo](https://github.com/refactormyself/basic-gtest). <s>Extended notes is [here](www.refactored.live/notes/basic-cli-app-cpp).</s>

### What does the app do?
The app simulates a fictitious zoo which has only CATs, DOGs and PENGUINs!
- list the available animals: `$ app -l`
- list all possible operations/actions by an animal: `$ app -l -a "cat"`
- Make an animal perform an action: `$ app -a "cat" -o "talk"`
- Show app version: `$ app --version`
- Show help: `$ app --help`

This is just a very functionality that come with the  [cli11 library](https://cliutils.github.io/CLI11/).
It is quite powerful, helping to lift the boilerplate of handling command line args. I have used the
[LLVM's command line tool](https://llvm.org/doxygen/CommandLine_8h_source.html), I prefer the cli11 library to it.
The only downside is if you plan to upstream into llvm.

### The Project also illustrates very basic stuffs like
- Command Line handling using a robust library like the [cli11 library](https://cliutils.github.io/CLI11/)
- Some C++ OOP stuff
- CMakeList file: [Top-level](./CMakeLists.txt) and [Test with gtest cmake setup](./test/CMakeLists.txt)
- [MakeFile](./Makefile) *(not used)*
- [Travis CI yaml file](./.travis.yml)

### Try it out
Just clone and to build run this script: `. ./run.sh`   
The name is **app**, see above for sample usage or `$./app --help`