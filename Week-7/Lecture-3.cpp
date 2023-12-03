#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;
bool checkArraySorted(int arr[], int &n, int index)
{
    if (index >= n - 1)
        return true;
    if (arr[index] > arr[index + 1])
        return false;

    return checkArraySorted(arr, n, index + 1);
}
int binarySearchUsingRecursion(int arr[], int start, int end, int &key)
{
    if (start > end)
        return -1;

    int mid = start + ((end - start) >> 1);

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchUsingRecursion(arr, mid + 1, end, key);
    else
        return binarySearchUsingRecursion(arr, start, mid - 1, key);
}
void findSubsequences(string &input, string &output, vector<string> &ans, int index)
{
    if (index >= input.size())
    {
        ans.push_back(output);
        return;
    }

    // Recursive call for including the current character
    output.push_back(input[index]);
    findSubsequences(input, output, ans, index + 1);

    // Recursive call for excluding the current character
    output.pop_back();
    findSubsequences(input, output, ans, index + 1);
}
// Subsequences can also be found out using BITMASKING
vector<string> generateSubsequences(const string &s)
{
    int n = s.length();
    vector<string> result;

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        string subsequence;
        for (int i = 0; i < n; ++i)
        {
            if ((mask & (1 << i)) > 0)
            {
                subsequence += s[i];
            }
        }
        result.push_back(subsequence);
    }

    return result;
}
int main()
{
    system("cls");

    int arr[] = {10, 20, 30, 40, 50, 60};
    int key = 60;
    int n = sizeof(arr) / sizeof(arr[0]);

    string input = "xy";
    string output = "";

    // Check if array sorted in ascending order or not
    cout << checkArraySorted(arr, n, 0);
    cout << "\n";

    // Binary Search using recursion
    cout << key << " is present at index : " << binarySearchUsingRecursion(arr, 0, n - 1, key);
    cout << "\n";

    // Printing the subsequences of a string
    cout << "Subsequences of " << input << " are : ";
    vector<string> ans;
    findSubsequences(input, output, ans, 0);
    for (string x : ans)
        cout << x << " ";
    cout << "\nSize of the vector is : " << ans.size();
    cout << "\n";

    vector<string> ans2 = generateSubsequences(input);
    for (string x : ans2)
        cout << x << " ";
    cout << "\nSize of the vector is : " << ans2.size();
    cout << "\n";
}