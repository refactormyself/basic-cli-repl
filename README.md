# A basic command line app with REPL using the [cli11 library](https://cliutils.github.io/CLI11/)
[![Build Status](https://app.travis-ci.com/refactormyself/basic-cli-repl.svg?branch=main)](https://app.travis-ci.com/refactormyself/basic-cli-repl)

This project add the REPL (Read Evaluate Print Loop) functionality to the [basic cli app demo](https://github.com/refactormyself/basic-cli-util).
<s>Extended notes on the concepts explored are discussed [here](www.refactored.live/notes/basic-repl-app-cpp).</s>

The app demonstrates among other concepts a simple sentence level parsing. 

### What does the app do?
The app simulates a fictitious zoo which has only CATs, DOGs and PENGUINs!   
***REPL mode:*** This is activated when the app is executed without any flag or option i.e. `$ app`. 
It drops to the app's REPL console `<app> _` 
- `<app> help()`: shows a brief description of the app.
- `<app> list()`: lists the available animals and possible actions/operations.
- `<app> cat walk`: issues a command that an animal: *cat* should perform an action: *walk*.
- `<app> exit()`: will exit the app.

***Non-REPL mode:*** when you add a flag or option
- list the available animals: `$ app -l`
- list all possible operations/actions by an animal: `$ app -l -a "cat"`
- Make an animal perform an action: `$ app -a "cat" -o "talk"`
- Show app version: `$ app --version`
- Show help: `$ app --help`
- Pass in a file of animal and action: `$ app -i data.txt` OR `$ app data.txt`   
    sample content of *data.txt*:
    ```
    cat walk
    dog talk
    penguin swim
    ```

This is just a very functionality that come with the  [cli11 library](https://cliutils.github.io/CLI11/).
It is quite powerful, helping to lift the boilerplate of handling command line args. I have used the
[LLVM's command line tool](https://llvm.org/doxygen/CommandLine_8h_source.html), but I prefer the cli11 library to it.
The only downside is that is not llvm stuff, which matters if you plan to upstream into llvm.

### The Project also illustrates very basic stuffs like
- Command Line handling using a robust library like the [cli11 library](https://cliutils.github.io/CLI11/)
- Basic design of a REPL app and very basic parsing.
- Basic software design of a cli app with both REPL and normal mode. 
  Like `$ python my_ai.py` versus `$ python` which drops you to `>>>_`
- Some C++ OOP stuff
- CMakeList file: [Top-level](./CMakeLists.txt) and [Test with gtest cmake setup](./test/CMakeLists.txt)
- [MakeFile](./Makefile) *(not used)*
- [Travis CI yaml file](./.travis.yml)

### Try it out
Just clone and to build run this script: `. ./run.sh`   
The name is **app**, see above for sample usage. REPL mode: `$ app`. Non-REPL mode: `$./app --help`