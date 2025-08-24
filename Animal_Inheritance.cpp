#include <iostream>
#include <string>
using namespace std;

class Animal{
protected:
    string name;

public:
    Animal(const string& animalName) : name(animalName){}
    virtual void makeSound() const = 0;
    virtual void feed() const{
        cout<< name <<" is being fed (Animal)." <<endl;}

    virtual void info() const{
        cout<<"Name: " << name <<endl;}

    virtual void info(int age) const{
        cout<<"Name: " << name <<" "<<"Age: " << age <<endl;}

    void identify() const{
        cout<< name <<" says: I am a generic Animal." <<endl;}

    virtual ~Animal(){
        cout<< name <<" has been removed from the zoo." <<endl;}
};

class Dog : public Animal{
public:
    Dog(const string& dogName) : Animal(dogName){}

    void makeSound() const override{
        cout<<"Woof Woof!" <<endl;}

    void feed() const override{
        cout<< name <<" is eating dog food." <<endl;}

    void info() const override{
        cout<<"Dog Name: " << name <<endl;}

    void info(int age) const override{
        cout<<"Dog Name: " << name << ", Dog Age: " << age <<endl;}

    void identify() const{
        cout<<"I am a Dog." <<endl;}
};

class Cat : public Animal{
public:
    Cat(const string& catName) : Animal(catName){}

    void makeSound() const override{
        cout<<"Meow!" <<endl;}

    void feed() const override{
        cout<< name <<" is eating cat food." <<endl;}

    void info() const override{
        cout<<"Cat Name: " << name <<endl;}

    void info(int age) const override{
        cout<<"Cat Name: " << name << ", Cat Age: " << age <<endl;}

    void identify() const{
        cout<<"I am a Cat." <<endl;}
};

class Bird : public Animal{
public:
    Bird(const string& birdName) : Animal(birdName){}

    void makeSound() const override{
        cout<<"Tweet!" <<endl;}

    void info() const override {
        cout<<"Bird Name: " << name <<endl;}

    void info(int age) const override{
        cout<<"Bird Name: " << name << ", Bird Age: " << age <<endl;}

    void identify() const{
        cout<<"I am a Bird." <<endl;}
};

int main(){
    int age=3;

    Animal* dog=new Dog("Karabaş");
    Animal* cat=new Cat("Pamuk");
    Animal* bird=new Bird("Cikcik");

    cout<<"Dog is a generic Animal, says:" <<endl;
    dog->makeSound();
    dog->feed();
    dog->info();
    dog->info(age);
    dog->identify();
    cout<<"------------------------" <<endl;

    cout<<"Cat is a generic Animal, says:" <<endl;
    cat->makeSound();
    cat->feed();
    cat->info();
    cat->info(age);
    cat->identify();
    cout<<"------------------------" <<endl;

    cout<<"Bird is a generic Animal, says:" <<endl;
    bird->makeSound();
    bird->feed();
    bird->info();
    bird->info(age);
    bird->identify();
    cout<<"------------------------" <<endl;

    delete dog;
    delete cat;
    delete bird;

    return 0;}
