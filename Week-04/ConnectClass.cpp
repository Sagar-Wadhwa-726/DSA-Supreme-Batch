/*The content of Week-4 was just revised, nothing new was done :)*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <malloc.h>
#include <map>
#include <time.h>
#include <set>
#include <stack>
#include <queue>
#include <hash_set>
using namespace std;
int main()
{
    system("cls");
    // vector<int> arr{5, 4, 3, 2, 1};
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size);
    for (int x : arr)
        cout << x << " ";
    return 0;
}