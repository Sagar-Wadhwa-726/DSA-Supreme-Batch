#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits>
#include <stack>
using namespace std;
class abc
{
private:
    mutable int x;
    int *y;
    int z;

public:
    // abc() : x(0), y(new int(0)) {}

    // This style of writing ctors is also known as initialisation list
    abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z)
    {
        cout << "these curly braces can have anything done inside them !\n";
        // z=10; gives error is z is const
    }

    int getX() const
    {
        // x = 50; gives error
        // const methods can't ever modify the data members of the class
        return x;
    }
    void setX(int x)
    {
        this->x = x;
    }
    int getY() const
    {
        int f = 20;
        // y = &f; gives error
        return *y;
    }
    void setY(int y)
    {
        *(this->y) = y;
    }
    int getZ() const
    {
        x = 20;
        return z;
    }
    void setZ(int z)
    {
        this->z = z;
    }
};
void printABC(const abc &a)
{

    cout << a.getX() << " " << a.getY() << " " << a.getZ() << "\n";
}
int main()
{
    system("cls");
    abc a = {1, 2, 3};
    // cout << a.getX() << " " << a.getY() << "\n";
    printABC(a);
    return 0;
}
int main2()
{
    system("cls");
    // CONST WITH VARIABLES
    // const int x = 5; // x is constant
    // initialised only once, reassigning not possible in case of constant variables
    // x=10;

    // Used to work in C compilers, not now :(, to change the value of a const variable
    // int *p = &x;
    // *p = 10;

    // cout << x << "\n";

    // CONST WITH POINTERS / CONST DATA-NON CONST POINTER
    // const int *a = new int(2);
    // int const *a = new int(2); // same as above
    // *a = 222; not allowed but pointer can be reassigned
    // *a = 2; // gives error since a is initialised with some garbage value which can't be modified
    // cout << *a << "\n";
    // memory leak if a not deleted
    // delete a;
    // Pointer itself can be reassigned
    // int b = 5;
    // a = &b;
    // cout << *a << "\n";

    // POINTER CONSTANT DATA NON CONST
    // int *const a = new int(2);
    // cout << *a << "\n";
    // *a = 222;
    // cout << *a << "\n";
    // int b = 99;
    // a = &b; gives error since it is a CONST POINTER, NON CONST DATA

    // CONST POINTER CONST DATA
    // const int *const a = new int(10); // constant data can be assigned only once
    // cout << *a << "\n";
    // *a=222; gives error
    // int b = 100;
    // a=&b; gives error

    return 0;
}