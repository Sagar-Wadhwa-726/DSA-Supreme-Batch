/*

    Homework question on - Move all the negative numbers to the left side of the array
    Also known as the Dutch national flag algorithm. Can be solved using the two pointer approach

    Time complexity = O(n)
    Space complexity = O(1)

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <limits>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    system("cls");
    vector<int> arr{-1, 2, -3, 4, -5, 6, 0, -5, 34, -7};
    // int l = 0;
    // int h = arr.size() - 1;
    // while (l < h)
    // {
    //     if (arr[l] < 0)
    //         l++;
    //     else if (arr[h] > 0)
    //         h--;
    //     else
    //         swap(arr[l], arr[h]);
    // }
    // for (auto x : arr)
    // {
    //     cout << x << " ";
    // }
    int start = 0;
    int l = 0; // denotes an index where a negative number can come
    while (start < arr.size())
    {
        // if the number is a positive number, just move forward
        if (arr[start] >= 0)
        {
            start++;
        }
        else
        {
            swap(arr[start], arr[l]);
            l++;
            start++;
        }
    }
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}