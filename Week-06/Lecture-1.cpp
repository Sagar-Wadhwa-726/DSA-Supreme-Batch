#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    system("cls");
    int x = 5;
    cout << "Value of x is : " << x << "\n";
    cout << "Address of x is : " << &x << "\n";

    // Dangling pointer -> bad practice, can happen that we are trying to access a memory
    // location which is outside of the program's memory location
    // int *ptr;

    // cout << *ptr;

    // Good practice is to use a nullptr
    // int *ptr = 0; int *ptr2 = nullptr;

    int a = 10;
    int *ptr = &a;

    cout << "Value of a is : " << a << "\n";
    cout << "Address of a is : " << &a << "\n";
    cout << "Value stored by ptr is : " << ptr << "\n";
    cout << "Value at address stored by ptr is : " << *ptr;

    return 0;
}