#include <iostream>

#include "animal_library.hpp"
#include "app_animal_visitor.hpp"

using namespace anim;
using namespace app;
int main() {
    // declare operations to be performed
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

    return 0;    return 0;
}
