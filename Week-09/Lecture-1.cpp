/*
PADDING AND GREEDY ALLIGNMENT : https://medium.com/@xsankalp13/padding-and-greedy-alignment-d2e3a843c35#:~:text=Greedy%20alignment%20is%20a%20technique,align%20the%20subsequent%20data%20members.

Empty class size -> 1 byte (minimum addressable space)

Acess modifiers define the scope of access of a data member and a member function.

If we want to access a private member outside the class, we can access it using the member functions only
since only they are present inside the class and can access these private members. These functions
are also known as getters and setters.

MEMORY LEAK : https://www.meetup.com/disruptive-tech-delhi/events/297770749/?read=1&_xtd=gatlbWFpbF9jbGlja9oAJDAzNmZiZWIwLTBlZjgtNGZjNS05M2ZjLTI4NjRiNjM5YjZiNw%253D%253D&_af=event&_af_eid=297770749

By default copy ctor does shallow copy, if we want to do deep copy, then we have to create our own copy ctor

*/
#include <iostream>
#include <string>
using namespace std;
class Animal
{
private:
    // Data members (state)
    int age;
    string name;

public:
    // Default ctor
    Animal()
    {
        age = 14;
        name = "rushil patel";
        cout << "default ctor called"
             << "\n";
    }

    ~Animal()
    {
        cout << "destructor called\n";
    }

    // Parameterised ctor
    Animal(int age, string name)
    {
        this->age = age;
        this->name = name;
        cout << "parameterised ctor called"
             << "\n";
    }

    // Copy ctor
    Animal(Animal &anotherAnimal)
    {
        this->age = anotherAnimal.age;
        this->name = anotherAnimal.name;
        cout << "copy ctor called"
             << "\n";
    }

    // Member functions (behaviours)
    void sleep()
    {
        cout << this->name << " is sleeping !"
             << "\n";
    }

    // Getter-> used to return the value of a data member
    int getAge()
    {
        return this->age;
    }

    // Setter-> used to set the value of the age data member
    void setAge(int age)
    {
        this->age = age;
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void print()
    {
        cout << this->age << " " << this->name << "\n";
    }
};
int main()
{
    system("cls");

    // Object allocation using static allocation
    // Animal brownie;

    // CAN BE DONE ONLY IF THE DATA MEMBERS ARE MARKED AS PUBLIC
    // brownie.age = 1;
    // brownie.name = "Brownie";

    // cout << "Age of brownie is : " << brownie.age << "\n";
    // cout << "Name of brownie is : " << brownie.name << "\n";

    // IN CASE THE DATA MEMBERS ARE MARKED AS PRIVATE AND NEED TO BE ACCESSED OUTSIDE THE CLASS
    // WE HAVE TO USE GETTERS AND SETTERS
    // brownie.setAge(12);
    // brownie.setName("Brownieeee");
    // cout << brownie.getAge() << "\n";
    // cout << brownie.getName() << "\n";
    // brownie.sleep();

    // Creating an object using dynamic memory allocation
    // Animal *animal = new Animal;

    // animal->setAge(45);
    // cout << animal->getAge() << "\n";

    // animal->setName("Sagar");
    // cout << animal->getName() << "\n";

    // cout << (*animal).getAge();

    // Default constructor will be called
    // Animal *a = new Animal;

    // Parameterised constructor will be called
    // Animal *b = new Animal(233, "rushil");
    // cout << b->getName() << " " << b->getAge() << "\n";

    // Copy constructor called
    // Animal c;
    // c.setAge(100);
    // c.setName("sher");

    // Animal d = c;
    // Animal d(c) // another way to call copy ctor
    // cout << d.getAge() << " " << d.getName() << "\n";
    // cout << c.getAge() << " " << c.getName() << "\n"; // prints the same value

    // Animal a;
    // a.setAge(20);
    // a.setName("Sagar");

    // Animal b = a;
    // a.print();
    // b.print();

    Animal sagar;
    sagar.setAge(21);
    sagar.setName("Sagar");
    cout << sagar.getAge() << " " << sagar.getName() << "\n";

    Animal *bagar = new Animal();
    bagar->setAge(22);
    bagar->setName("Bagar");
    cout << bagar->getAge() << " " << bagar->getName() << "\n";

    // To call the destructor to deallocate the memory for the dynamically created object, we need to call
    // the destructor manually using the delete keyword.
    delete bagar;

    return 0;
}