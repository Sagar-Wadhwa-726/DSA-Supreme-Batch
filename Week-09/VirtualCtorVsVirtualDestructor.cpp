// Virtual constructors can't be made
// Virtual destructors can be made, and should be made to avoid any kind of memory leak. When virtual destructor is called, it is like no no no this destructor does not needs to be called, firstly call the destructor of the derived class and then the base class.
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
class Base
{
public:
    Base()
    {
        cout << "ctor of base class called !\n";
    }
    virtual ~Base()
    {
        cout << "dtor of base class called !\n";
    }
};
class Derived : public Base
{
    int *a;

public:
    Derived()
    {
        a = new int[10000];
        cout << "ctor of derived class called !\n";
    }
    ~Derived()
    {
        delete[] a;
        cout << "dtor of derived class called !\n";
    }
};
int main()
{
    system("cls");
    Base *base = new Derived;
    delete base;
    return 0;
}