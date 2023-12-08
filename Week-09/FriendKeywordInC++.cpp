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
class A
{
private:
    int x;

public:
    A(int _val) : x(_val){};

    int getX() const
    {
        return x;
    }

    void setX(int val)
    {
        x = val;
    }

    void print() const
    {
        cout << this->x;
    }

    // friend class B;
    // friend void print(const A &);
};

// This class prints the data members of class A
// Friend class -> can access the private members of the class
class B
{
public:
    void print(const A &a)
    {
        // cout << a.getX() << "\n";

        // We want to directly access the private data member
        // cout << a.x;
        a.print();
    }
};

// Friend function -> can access the private members of the class
// void print(const A &a)
// {
//     cout << a.x;
// }
int main()
{
    system("cls");
    A a(5);
    B b;
    b.print(a);
    // print(a);
    return 0;
}