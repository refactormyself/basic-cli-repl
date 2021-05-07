#ifndef ANIMAL_LIBRARY_HPP
#define ANIMAL_LIBRARY_HPP

#include <memory>

namespace anim {

    class Dog;
    class Cat;
    class Bird;
    class Penguin;

// @visitor pattern: This is the "VISITOR" Class interface
// (Put custom object operations in here, not in their Class def.)
    class Operation // VISITOR Class interface
    {
    public:
        virtual void dogOperation(Dog &dog) = 0;

        virtual void catOperation(Cat &cat) = 0;

        virtual void birdOperation(Bird &bird) = 0;

        virtual void pengOperation(Penguin &peng) = 0;

        virtual void pengOperation(Bird &peng) = 0; // multiple visitable states
        virtual void pengOperation(Penguin &peng, std::string location) = 0; // multiple visitable states
    };

    class Animal {
    protected:
        std::string message;
    public:
        // @visitor pattern: this is the ACCEPT; where visitors are accepted :)
        virtual std::string perform(Operation &op) = 0;
        // with these we handle multiple visitable states
        // virtual void perform(Operation &op, Bird bird)= 0;
        // virtual void perform(Operation &op, std::string location)= 0;

        void setMessage(std::string msg){
            message = msg;
        }
    };

    class Dog : public Animal {
    public:
        Dog() { std::cout << "\nI am a Dog!\n"; }

        std::string perform(Operation &op) override {
            message = ""; // clear previous messages
            op.dogOperation(*this); // sets the message
            return message;
        }
    };

    class Cat : public Animal {
    public:
        Cat() { std::cout << "\nI am a Cat!\n"; }

        std::string perform(Operation &op) override {
            message = ""; // clear previous messages
            op.catOperation(*this);
            return message;
        }
    };

    class Bird : public Animal {
    public:
        Bird() { std::cout << "\nI am a Bird!\n"; }

        std::string perform(Operation &op) override {
            message = ""; // clear previous messages
            op.birdOperation(*this);
            return message;
        }
    };

    class Penguin : public Bird {
    public:
        Penguin() { std::cout << "\nI am a Penguin!\n"; }

        std::string perform(Operation &op) override {
            message = ""; // clear previous messages
            op.pengOperation(*this);
            return message;
        }
    };

}

#endif //ANIMAL_LIBRARY_HPP