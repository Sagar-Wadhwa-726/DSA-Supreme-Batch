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
int main()
{
    system("cls");
    vector<int> v = {3, 4, 1, 2};
    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
    return 0;
}