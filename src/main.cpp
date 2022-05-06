#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "animal_library.hpp"
#include "app_animal_visitor.hpp"
#include "zoo.hpp"

// APP GLOBAL VARIABLES: store values of command line flags and options
int LIST_FLAG = 0; // e.g: app -l OR app --list
std::string ANIMAL_OPTION; // e.g: app --animal="cat" OR app -a="cat"
std::string ACTION_OPTION; // e.g: app --operation="swim" OR app -o="swim"
std::string FILENAME; // redundant file handling

void visitAnimals();
void visitZoo(CLI::App &app);
void handleCommands(CLI::App &app);

void processCodeLine(const std::string &codeLine);

using namespace anim;
using namespace app;

int main(int argc, char **argv) {

    ///// SETUP --
    std::string APP_VERSION = "0.00.0";

    // describe the app
    CLI::App app("This is a basic command line REPL app, that simulate a visit to a fictitious zoo!"
                 "\nIt uses the cli11 library: cliutils.github.io/CLI11/"
                 "\n Basic use: <app> animal action"
                 "\n       e.g: <app> cat walk");

    // set therespoce to  --version
    app.set_version_flag("--version",
                         APP_VERSION + "; using cli11 version "
                         + std::string(CLI11_VERSION) + ".");

    handleCommands(app);

    ///// AFTER SETUP process the args
    CLI11_PARSE(app, argc, argv);

    ///// NOW use the app
    visitZoo(app);

    // if you uncomment this the function will execute each time the app runs. Good for license warning!
    // visitAnimals();

    return 0;
}

void handleCommands(CLI::App &app) {
    // input file (positional)
    CLI::Option *inputOpt = app.add_option("-i,--in,file",
                                           FILENAME,
                                           "Input File name. The file contains two space delimited "
                                           "strings per each line.\nIt of the form <animal> <action>."
                                           " e.g: `cat talk`");
    CLI::Option *listFlag = app.add_flag("-l,--list", LIST_FLAG,
                                     "lists all available animals.\n"
                                     "If the `--animal` option is set; lists all possible actions.");
    CLI::Option *animalOption = app.add_option("-a,--animal", ANIMAL_OPTION,
                                               "Sets the animal. e.g `-a \"cat\"`.");
    CLI::Option *actionOption = app.add_option("-o,--operation", ACTION_OPTION,
                                               "Sets the operation/action to be performed "
                                               "by an animal. e.g `-a \"cat\" -o \"walk\"`.");
}

void visitZoo(CLI::App &app) {
//    - list available animals `$ app -l --list` ==> cat, dog, penguin
//    - @animal-x list possible operations
//    - @animal-x perform operation-y

    if (!FILENAME.empty()){
        if (!ACTION_OPTION.empty() || !ACTION_OPTION.empty() || LIST_FLAG > 0){
            std::cout << "You have set the input file: " << FILENAME
                      << ".\nOther flags and options cannot be used with the file input option.\n"
                         "Please, use `--help` to see usage." <<'\n';
            return;
        }

        // handle file
        std::ifstream fileStrm;
        fileStrm.open(FILENAME);
        if(!fileStrm) {
            std::cerr << "Error: the supplied file: "<< FILENAME << " could not be opened!" << std::endl;
            exit(1);
        }

        std::string codeLine;
        while (std::getline(fileStrm, codeLine)) {
            processCodeLine(codeLine);
        }
        return;
    }

    if (!ACTION_OPTION.empty() && LIST_FLAG > 0){
        std::cout << "You cannot set the list flag and the action option together.\n"
                     "Please, use `--help` to see usage." <<'\n';
        return;
    }

    if (!ACTION_OPTION.empty() && ANIMAL_OPTION.empty()){
        std::cout << "You have selected the operation: " << ACTION_OPTION
                  << ".\n Please use `-a` or `--animal` to set an animal for this operation." << '\n';
        return;
    }

    if (LIST_FLAG > 0){
        // list possible action for selected animal
        if (!ANIMAL_OPTION.empty()) {
            std::cout << Zoo::getActions(ANIMAL_OPTION) <<'\n';
            return;
        }

        // list all animals
        std::cout << "Here are the animals in this zoo: " <<'\n';
        for (const auto& anim : Zoo().getAnimals())
            std::cout << anim  <<'\n';

        return;
    }

    if (!ACTION_OPTION.empty() && !ANIMAL_OPTION.empty())
        std::cout << Zoo::performAction(ANIMAL_OPTION, ACTION_OPTION)  <<'\n';

    // All valid args have been handled, so drop to REPL mode
    // NOTE that the parsing is done at line level even in none REPL mode: `$ app -i data.txt`

    std::cout << "This is the REPL mode.\n"
              << "In Built commands are: `help()`, `exit()`, `list()`"
              << std::endl;

    std::string tokenLine; // NOTE: I am not breaking the line into tokens here.

//    fprintf(stderr, "<app> ");
    std::cout << "<app> ";
    while (getline(std::cin, tokenLine)) { // stops at EOF or error
        if (tokenLine == "exit()")
            break;

        if (tokenLine == "help()") {
            std::cout << app.get_description();
            tokenLine = "list()"; // fall through to next if-statement
        }

        if (tokenLine == "list()") {
            std::cout << '\n' << "List of animals: 'cat', 'dog', 'penguin'"
                      << '\n' << "List of possible actions: 'talk', 'walk', 'swim'\n";
            std::cout << "<app> ";
            continue;
        }

        processCodeLine(tokenLine);
        fprintf(stderr, "<app> ");
    }
}

void processCodeLine(const std::string &codeLine) {
    std::istringstream iss(codeLine);
    std::string animal, action;
    std::getline(iss, animal, ' ' );
    std::getline(iss, action, ' ' );

    std::cout << Zoo::performAction(animal, action) << '\n';
}

void visitAnimals() {
    Talk talk;
    Walk walk;

    Cat cat;
    std::cout << cat.perform(talk) << "! \n";
    std::cout << cat.perform(walk) << "! \n";

    Dog dog;
    std::cout << dog.perform(talk) << "! \n";
    std::cout << dog.perform(walk) << "! \n";

    Bird bird;
    std::cout << bird.perform(talk) << "! \n";
    std::cout << bird.perform(walk) << "! \n";

    Penguin penguin;
    std::cout << penguin.perform(talk) << "! \n";
    std::cout << penguin.perform(walk) << "! \n";

}