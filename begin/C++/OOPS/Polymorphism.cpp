#include<iostream>
using namespace std;

class Animal{
public:
    virtual void sound(){
        cout << "some sound" << endl;
    }
};

class Dog : Animal{
public:
    void sound(){
        cout << "bow wow" << endl;
    }

};

class Cat : Animal{
public:
    void sound(){
        cout << "meow meow" << endl;
    }

};

class Duck : Animal{
public:
    void sound(){
        cout << "quack quack" << endl;
    }

};

int main(){
    Animaal animals[4];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Duck();
    for(int i = 0; i < 4; i++){
        animals[i]->sound();
    }
    return;
}