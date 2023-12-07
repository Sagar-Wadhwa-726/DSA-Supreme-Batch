#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;
class Animal
{
public:
    Animal()
    {
        cout << "PARENT CTOR\n";
    }
    void speak()
    {
        cout << "Animal is speaking !\n";
    }
};
class Dog : public Animal
{
public:
    Dog()
    {
        cout << "CHILD CTOR\n";
    }
    void speak()
    {
        cout << "Dog is barking !\n";
    }
};
int main()
{
    system("cls");
    // Animal *animal = new Animal;
    // animal->speak();

    // Dog *dog = new Dog;
    // Calls the method of the dog class, if the speak method was not overriden then the speak method of the parent class would have been called
    // dog->speak();

    Animal *animal = new Animal;
    animal->speak();

    Dog *dog = new Dog;
    dog->speak();

    // Upcasting, where the pointer is of the type of the parent class and the object is of the type of the child class.
    Animal *a = new Dog;
    a->speak();

    // Downcasting where the pointer is of the type of the child class and the object is of the type fo the parent class
    Dog *d = (Dog *)new Animal;
    d->speak();

    // Without the use of the virtual keyword it always depends on the type of the reference variable/pointer and not the object in determining that which class's method will be called.

    // With the use of the virtual keyword, it is the opposite. Now it depends on the type of the object in determining that which class's method will be called.

    // Using dynamic memory allocation to allocate memory to 2D ARRAY
    int row = 5;
    int col = 3;
    int count = 0;
    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = count++;
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}