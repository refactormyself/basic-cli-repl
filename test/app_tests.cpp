#include <string>
#include <gtest/gtest.h>

#include "animal_library.hpp"
#include "app_animal_visitor.hpp"

namespace {
    using namespace anim;
    using namespace app;
    
    TEST (BasicVisitorPatternTests_1 /*test suite name*/, A_Cat_Should_Walk /*test name*/) {
        Walk walk;

        Cat cat;
        ASSERT_NE ("", cat.perform(walk));
    
    }

    TEST (BasicVisitorPatternTests_1 /*test suite name*/, A_Cat_Should_Talk_Meow /*test name*/) {
        Talk talk;

        Cat cat;
        ASSERT_EQ ("Meow", cat.perform(talk));
    
    }

    class Swim : public anim::Operation {
    public:
        void dogOperation(anim::Dog &dog) override {}

        void catOperation(anim::Cat &cat) override {}

        void birdOperation(anim::Bird &bird) override {}

        void pengOperation(anim::Penguin &peng) override {
            peng.setMessage("Yeah! Let's go swimming.");
        }

        void pengOperation(anim::Bird &peng) override {
            peng.setMessage("Oh nooo! I can't swim in Bird mode.");
        }

        void pengOperation(anim::Penguin &peng, std::string location) override {
            if(location == "water")
                peng.setMessage("Yeah! Let's go swimming.");
        }
    };
    
    TEST (BasicVisitorPatternTests_1 /*test suite name*/, A_Cat_Should_Not_Swim /*test name*/) {
        Swim swim;

        Cat cat;
        ASSERT_TRUE (cat.perform(swim).empty());
    
    }

    TEST (BasicVisitorPatternTests_2 /*test suite name*/, A_Penguin_Should_Swim /*test name*/) {
        Swim swim;

        Penguin penguin;
        ASSERT_FALSE (penguin.perform(swim).empty());
    
    }


}