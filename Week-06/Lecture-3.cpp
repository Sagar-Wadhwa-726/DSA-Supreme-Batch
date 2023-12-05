#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void solve(int **ptr)
{
    ptr = ptr + 1;
}
int *solve2()
{
    int a = 5;
    int *ans = &a;
    return ans;
}
int main()
{
    system("cls");
    // int a = 5;
    // int *p = &a;
    // int **q = &p;

    // cout << &a << "\n";
    // cout << a << "\n";
    // cout << p << "\n";
    // cout << &p << "\n";
    // cout << *p << "\n";
    // cout << q << "\n";
    // cout << &a << "\n";
    // cout << *q << "\n";
    // cout << **q << "\n";

    // int x = 12;
    // int *p = &x;
    // int **q = &p;
    // solve(q);

    // Reference variables are used instead of pointers these days
    // int a = 5;
    // int &b = a;

    // cout << b; // here only entry in symbol table is stored and no seperate memeory allocated
    // to variable a

    int *q = solve2();
    cout << *(q) << " ";

    // return 0;
}