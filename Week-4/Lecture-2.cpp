#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

/*Find pivot element in an array*/

int pivotFinder(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int m;
    while (s <= e)
    {
        if (s == e)
            return s;
        m = s + (e - s) / 2;
        if (m + 1 < arr.size() && arr[m] > arr[m + 1])
        {
            return m;
        }
        else if (m - 1 >= 0 && arr[m] < arr[m - 1])
        {
            return m - 1;
        }
        else if (arr[m] <= arr[s])
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return -1;
}

/*Finding the square root of a number using binary search*/
int sqrtbs(int x)
{
    long long s = 0;
    long long e = x;
    long long m;
    int ans = -1;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (m * m < x)
        {
            // Store the answer and search in the hope of a better answer on the right hand side
            ans = m;
            s = m + 1;
        }
        else if (m * m == x)
        {
            return m;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

/*Function to perform binary search in a 2D-Array*/
bool binarySearchmatrix(vector<vector<int>> &arr, int x)
{
    int s = 0;
    int e = arr.size() * arr[0].size() - 1;
    int mid = s + (e - s) / 2;
    int rows = arr.size();
    int cols = arr[0].size();
    while (s <= e)
    {
        int rowIndex = mid / cols;
        int columnIndex = mid % cols;
        if (arr[rowIndex][columnIndex] == x)
        {
            cout << "Found at : " << rowIndex << " " << columnIndex << " ";
            return true;
        }
        else if (arr[rowIndex][columnIndex] > x)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return false;
}

int main()
{
    system("cls");
    vector<int> arr{1, 2, 3, 4, 0, 1};
    vector<vector<int>> arr1{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}};
    int precesion, number;
    cout << "The pivot element is : " << arr[pivotFinder(arr)] << "\n";
    // cout << "Enter the precesion : ";
    // cin >> precesion;
    // cout << "Enter the number : ";
    // cin >> number;
    // int ans = sqrtbs(number);
    // double finalAnswer = ans;
    // cout << "The square root of " << number << " is : ";
    // double step = 0.1;
    // for (int i = 0; i < precesion; i++)
    // {
    //     for (double j = finalAnswer; j * j <= number; j = j + step)
    //     {
    //         finalAnswer = j;
    //     }
    //     step = step * 0.1;
    // }
    // cout << finalAnswer << "\n";
    binarySearchmatrix(arr1, 19);
    return 0;
}

// On the similar lines (as on the qeustion based on finding the pivot element index), the question on leetcode which is finding in a rotated and sorted array can be done
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Finding the square root of a number using binary search
// https://leetcode.com/problems/sqrtx/