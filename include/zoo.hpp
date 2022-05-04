#ifndef ZOO_HPP
#define ZOO_HPP

#include <array>
#include <string>

namespace app{

    // we define a new action
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

    class Zoo{
    public:
        [[nodiscard]]
        const std::array<std::string, 3> &getAnimals() const {
            return animals;
        }

        static std::string getActions(const std::string& animal){
            if (animal == "cat" || animal == "dog")
                return "talk, walk";

            if (animal == "penguin")
                return "talk, walk, swim";

            return animal + " : Unknown animal!!! Only cat, dog and penguin are in this zoo.";
        }

        static std::string performAction(const std::string& animal, const std::string& action){
            if( !(animal == "cat" || animal == "dog" || animal == "penguin") )
                return "Unknown animal!!! Only cat, dog and penguin are in this zoo.";

            if (action == "talk"){
                Talk talk;
                if (animal == "cat")
                    return anim::Cat().perform(talk);

                if (animal == "dog")
                    return anim::Dog().perform(talk);

                if (animal == "penguin")
                    return anim::Penguin().perform(talk);
            }

            if (action == "walk"){
                Walk walk;
                if (animal == "cat")
                    return anim::Cat().perform(walk);

                if (animal == "dog")
                    return anim::Dog().perform(walk);

                if (animal == "penguin")
                    return anim::Penguin().perform(walk);
            }

            if (action == "swim"){
                Swim swim;
                if (animal == "cat")
                    return anim::Cat().perform(swim);

                if (animal == "dog")
                    return anim::Dog().perform(swim);

                if (animal == "penguin")
                    return anim::Penguin().perform(swim);
            }

            return "animal: " + animal + "; action: " + action
                   + "\nThe only possible actions in this zoo "
                   "(of cats, dogs and penguins) are: talk, walk, swim";
        }

    private:
        std::array<std::string, 3> animals = {"cat", "dog", "penguin"};

    };
}

// TODO:
//   - gtest the Zoo class
//   - `./app -a "cat" -o "yy"`
//   - `./app -a "cat" -o " "`
#endif //ZOO_HPP