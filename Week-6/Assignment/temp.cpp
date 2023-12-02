#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    system("cls");
    char ch = 'a';
    char *ptr = &ch;
    ch++;
    cout << *ptr;
    return 0;
}