#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    system("cls");
    char name[100];
    // cin >> name;
    cin.getline(name, 100);

    // By default cin stops taking input when a space occurs
    // If we want to take the input as the whole name, then use the getline method
    cout << name;

    // Reverse string question on leetcode
    // https://leetcode.com/problems/reverse-string/description/

    // character array is a data structure
    // whereas a string is a data type in C++

    // https://cplusplus.com/reference/string/string/

        return 0;
}