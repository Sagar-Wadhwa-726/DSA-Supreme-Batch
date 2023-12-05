#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
#include <limits>
using namespace std;
int main()
{
    system("cls");
    vector<int> arr{1, 3, 3, 3, 2};
    // Visited method
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int index = abs(arr[i]);
    //     if (arr[index - 1] > 0)
    //         arr[index - 1] *= -1;
    // }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] > 0)
    //         cout << i + 1 << " is missing!\n";
    // }

    // Sorting + Swapping method, bring every element to it's correct position
    // Here the index is assumed to be 1 based
    int i = 0;
    while (i < arr.size())
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (i + 1 != arr[i])
        {
            cout << "Missing element is : " << i + 1;
            cout << "\n";
        }
    }
    return 0;
}