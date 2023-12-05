#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <algorithm>
#include <limits>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*Function of binary search*/
int binarySearch(vector<int> &arr, int key)
{
    // Binary search condition - Array should be sorted either in ascending order or opposite
    // (monotonic order)
    // Time Complexity - O(logn), Space complexity - O(1)
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

/*Function for finding the first occurence of the element in an array*/

int firstOccurrence(vector<int> &arr, int key)
{
    // if the array is sorted we can apply binary search on it
    int ans = -1;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // if the element is found, it can be the first occurence or it can happen so that
        // there is the element's first occurence present on the LHS.
        if (arr[mid] == key)
        {
            // store the answer
            ans = mid;
            // search for the first occurence (if any) on the LHS
            end = mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

/*Function for finding the last occurence of the element in an array*/

int lastOccurrence(vector<int> &arr, int key)
{
    // if the array is sorted we can apply binary search on it
    int ans = -1;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // if the element is found, it can be the last occurence or it can happen so that
        // there is the element's last occurence present on the RHS.
        if (arr[mid] == key)
        {
            // store the answer
            ans = mid;
            // search for the last occurence (if any) on the RHS
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    system("cls");
    vector<int> arr{1, 2, 4, 6, 5, 11, 15, 19, 23};
    vector<int> arr2{1, 3, 4, 4, 4, 4, 4, 6, 7, 9};

    // STL FOR BINARY SEARCH
    // binary_search(arr.begin(), arr.end(), 4)
    cout << binarySearch(arr, 2);
    cout << "\n";
    cout << "First occurrence of 4 is : " << firstOccurrence(arr2, 4); // can be done using lower_bound
    cout << "\n";
    cout << "Last occurrence of 4 is : " << lastOccurrence(arr2, 4); // can be done using upper_bound
    cout << "\n";
    cout << "Total number of occurrences of 4 are : " << lastOccurrence(arr2, 4) - firstOccurrence(arr2, 4) + 1;
    cout << "\n";
    return 0;
}

// HW - Find the missing element using binary search, square root using binary Search, Search in a rotated and a sorted array, Find pivot using binary search.

// Peak element in a mountain array question done on leetcode
