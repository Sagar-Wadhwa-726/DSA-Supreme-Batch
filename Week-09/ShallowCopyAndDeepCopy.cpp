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
class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // If we don't write our own copy ctor, automatically this same dumb copy ctor will be inserted by c++
    // which does shallow copy
    // abc(const abc &obj)
    // {
    //     this->x = obj.x;
    //     this->y = obj.y;
    // }

    // OUR OWN SMART DEEP COPY CTOR
    abc(const abc &obj)
    {
        this->x = obj.x;
        this->y = new int((*obj.y));
    }

    // const means it can't change/modify the data members
    const void print()
    {
        printf("X : %d\nPTR Y : %p\nCONTENT OF Y : %d\n\n", x, y, *y);
    }

    ~abc()
    {
        delete y;
    }
};
using namespace std;
int main()
{
    system("cls");
    abc a(1, 2);
    cout << "PRINTING FOR A\n";
    a.print();

    abc b(a);
    cout << "PRINTING FOR B\n";
    b.print();

    (*a.y) = 99;

    cout << "PRINTING FOR B\n";
    b.print();

    abc *object = new abc(1, 2);
    abc another = *object;

    cout << "PRINTING FOR OBJECT\n";
    object->print();
    delete object;

    cout << "PRINTING FOR ANOTHER\n";
    another.print();
    return 0;
}