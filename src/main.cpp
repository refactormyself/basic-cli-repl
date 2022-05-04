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

using namespace anim;
using namespace app;

int main(int argc, char **argv) {

    ///// SETUP --
    std::string APP_VERSION = "0.00.0";

    // describe the app
    CLI::App app("This is a basic command line app, that simulate a visit to a fictitious zoo!"
                 "\nIt uses the cli11 library: cliutils.github.io/CLI11/");

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
                                           FILENAME, "Input File name");
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
        // handle file
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
        Zoo::performAction(ANIMAL_OPTION, ACTION_OPTION);

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