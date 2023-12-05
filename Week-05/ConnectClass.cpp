#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
// Custom Comparator
bool cmp(char a, char b)
{
    return a < b;
}
int main()
{
    system("cls");
    string name = "sagar";
    sort(name.begin(), name.end(), cmp);
    cout << name;
    return 0;
}

// https://leetcode.com/problems/largest-number/