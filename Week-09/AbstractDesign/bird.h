// VENDOR PROVIDES THIS HEADER FILE
#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

// THIS ACTS AS AN INTERFACE
class Bird
{
public:
    // pure virtual function, now this class becomes an interface
    // Bird does not have any concrete existence of it's own since birds are of many types like Sparrow,
    // Eagle etc. Any class which inherits this Bird class has to mandatoroly define these methods (implement them).
    virtual void eat() = 0;
    virtual void fly() = 0;
};

// ALL OF THE BELOW CLASSES ACT AS AN IMPLEMENTATION
class Sparrow : public Bird
{
private:
    void eat()
    {
        std::cout << "Sparrow is eating !\n";
    }
    void fly()
    {
        std::cout << "Sparrow is flying !\n";
    }
};

class Eagle : public Bird
{
private:
    void eat()
    {
        std::cout << "Eagle is eating !\n";
    }
    void fly()
    {
        std::cout << "Eagle is flying !\n";
    }
};

class Piegon : public Bird
{
private:
    void eat()
    {
        std::cout << "Piegon is eating !\n";
    }
    void fly()
    {
        std::cout << "Piegon is flying !\n";
    }
};

#endif