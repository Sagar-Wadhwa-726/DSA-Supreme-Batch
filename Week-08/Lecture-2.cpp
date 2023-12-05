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
int partition(vector<int> &arr, int start, int end)
{
    // Selecting the pivot element
    int pivotIndex = start;

    // Bring the pivot element to its correct position
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= arr[pivotIndex])
            count++;
    }
    swap(arr[pivotIndex], arr[start + count]);
    pivotIndex = start + count;

    // Check for any violation
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
            i++;
        while (arr[j] > arr[pivotIndex])
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}
void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int pivotElementIndex = partition(arr, start, end);

    quickSort(arr, start, pivotElementIndex - 1);
    quickSort(arr, pivotElementIndex + 1, end);
}
void printPossiblePermutation(string &str, int i)
{
    if (i >= str.size())
    {
        cout << str << " ";
        return;
    }

    // swapping
    for (int j = i; j < str.size(); j++)
    {
        swap(str[i], str[j]);
        printPossiblePermutation(str, i + 1);

        // backtrack -> to return back to the original state/string
        swap(str[i], str[j]);
    }
}
int main()
{
    system("cls");

    // Quick Sort
    vector<int> arr{8, 1, 20, 30, 6, 5, 60, 5};
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    // Printing all the possible permutation of the string
    string str = "abc";
    printPossiblePermutation(str, 0);

    return 0;
}