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
void merge(vector<int> &nums, int start, int end)
{
    int mid = start + ((end - start) >> 1);

    int len1 = mid - start + 1;
    int len2 = end - (mid);

    int *left = new int[len1];
    int *right = new int[len2];

    int k = start;

    for (int i = 0; i < len1; i++)
        left[i] = nums[k++];

    k = mid + 1;

    for (int i = 0; i < len2; i++)
        right[i] = nums[k++];

    int i = 0;
    int j = 0;
    k = start;

    while (i < len1 && j < len2)
    {
        if (left[i] < right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }
    while (i < len1)
        nums[k++] = left[i++];
    while (j < len2)
        nums[k++] = right[j++];
}
void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + ((end - start) >> 1);

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, end);
}
int main()
{
    system("cls");
    vector<int> arr{38, 27, 43, 3, 9, 20};

    // Merge sort
    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";
    cout << "\n";
    return 0;
}