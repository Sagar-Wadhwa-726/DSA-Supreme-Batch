#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
using namespace std;

/*Function to perform binary serach in a nearly sorted array*/
int nearlySortedArrayBinarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
            return mid;
        else if (arr[mid - 1] == target && mid - 1 >= 0)
            return mid - 1;
        else if (arr[mid + 1] == target && mid + 1 < arr.size())
            return mid + 1;
        else if (arr[mid] > target)
            end = mid - 2;
        else
            start = mid + 2;
        mid = start + (end - start) / 2;
    }
    return -1;
}

/*Function to find the odd occuring element*/
int oddOccuringElement(vector<int> &arr)
{
    // Answer always lies on the even index
    int s = 0;
    int e = arr.size() - 1;
    int m = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
            return s;
        if (m % 2 == 0)
        {
            // if true, we are on the left hand side, search on the right hand side
            if (arr[m] == arr[m + 1])
                s = m + 2;
            // we are on the right hand side, search in the left hand side
            else
                e = m;
        }
        else
        {
            // if true we are in the left hand side, search in the right hand side
            if (arr[m] == arr[m - 1])
                s = m + 1;
            // we are on the right hand side, search on the left hand side
            else
                e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    system("cls");
    vector<int> arr{10, 3, 40, 20, 50, 80, 70};
    vector<int> arr2{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 1, 1, 2, 2, 3, 3, 100, 100};
    // int target = 80;
    // cout << target << " is present at index : " << nearlySortedArrayBinarySearch(arr, target);

    int ans = oddOccuringElement(arr2);
    cout << "Odd occuring element is : " << arr2[ans];
    return 0;
}

// Dividing two numbers using binary Search
// https://leetcode.com/problems/divide-two-integers/
