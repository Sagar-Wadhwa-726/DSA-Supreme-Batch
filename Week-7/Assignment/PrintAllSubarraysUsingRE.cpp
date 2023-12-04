#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
void printSubarray_util(vector<int> &arr, int start, int end)
{
    // base case
    if (end >= arr.size())
        return;

    // solve one case
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // rest will be handled by recursion

    printSubarray_util(arr, start, end + 1);
}
void printSubarray(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        printSubarray_util(nums, start, start);
        cout << "\n";
    }
}
int main()
{
    system("cls");
    vector<int> arr{1, 2, 3, 4, 5};
    printSubarray(arr);
    return 0;
}