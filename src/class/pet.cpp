#include <iostream>

using namespace std;

class Pet {
public:
    virtual string speak() = 0;
    virtual string get_name() = 0;
    void say_hi() {
        cout << get_name() << " says: \"" + speak() + "\"" << endl;
    }
};

class Dog : public Pet {
    string name;
public:
    Dog(string name) : name{ name } {};
    string speak() {
        return "Woof";
    }
    string get_name() {
        return name;
    }
};

class Cat : public Pet {
    string name;
public:
    Cat(string name) : name{ name } {};
    string speak() {
        return "Meow";
    }
    string get_name() {
        return name;
    }
};

void pet_say_hi(Pet& pet) {
    pet.say_hi();
}

int main() {
    Dog coco("Coco");
    Cat yuki("Yuki");
    coco.say_hi();
    yuki.say_hi();
    pet_say_hi(coco);
    pet_say_hi(yuki);
}