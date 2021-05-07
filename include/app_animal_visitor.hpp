#ifndef APP_ANIMAL_VISITOR_HPP
#define APP_ANIMAL_VISITOR_HPP

#include <iostream>

#include "animal_library.hpp"

namespace app {

    // Talk is an Operation. So, implement how you want your object to sound!
    class Talk : public anim::Operation {
    public:
        void dogOperation(anim::Dog &dog) override {
            dog.setMessage("Woof");
        }

        void catOperation(anim::Cat &cat) override {
            cat.setMessage("Meow");
        }

        void birdOperation(anim::Bird &bird) override {
            bird.setMessage("Hissss");
        }

        void pengOperation(anim::Penguin &peng) override {
            peng.setMessage("Quirk");
        }

        void pengOperation(anim::Bird &peng) override {
            // std::cout << "A penguin is a bird. So ... ";
            birdOperation(peng);
        }

        void pengOperation(anim::Penguin &peng, std::string location) override {
        }
    };

// This is done without changing any of the above classes

    // Walk is an Operation. So, implement how you want your object to move!
    class Walk : public anim::Operation {
    public:
        void dogOperation(anim::Dog &dog) override {
            dog.setMessage("Dogs run");
        }

        void catOperation(anim::Cat &cat) override {
            cat.setMessage("Cats sneak");
        }

        void birdOperation(anim::Bird &bird) override {
            bird.setMessage("Birds fly fly fly");
        }

        void pengOperation(anim::Penguin &peng) override {
            birdOperation(peng); // going down the object hierarchy
            peng.setMessage("Penguins swim and walk");
        }

        void pengOperation(anim::Bird &peng) override {
            // std::cout << "A penguin is a bird. And ... ";
            birdOperation(peng);
        }

        void pengOperation(anim::Penguin &peng, std::string location) override {
            if (location == "land")
                peng.setMessage("Penguins walk on land!");
            else if (location == "water")
                peng.setMessage("Penguins swim in water!");
            else
                peng.setMessage("Penguins swim and walk!");
        }
    };
}
#endif //APP_ANIMAL_VISITOR_HPP
