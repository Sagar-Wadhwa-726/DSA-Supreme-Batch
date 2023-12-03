#include <iostream>
#include <vector>
using namespace std;
void printArrayUsingRecursion(int arr[], int n, int index)
{
    if (index >= n)
        return;

    cout << arr[index] << " ";

    printArrayUsingRecursion(arr, n, index + 1);
}
int findMaxInArray(int arr[], int n, int index, int max)
{
    if (index >= n)
        return max;

    if (arr[index] > max)
    {
        max = arr[index];
    }
    return findMaxInArray(arr, n, index + 1, max);
}
void finMinInArray(int arr[], int n, int index, int &min)
{
    if (index >= n)
        return;

    if (arr[index] < min)
    {
        min = arr[index];
    }
    finMinInArray(arr, n, index + 1, min);
}
bool isPresent(string &name, int index, char &key)
{
    if (index >= name.size())
        return false;

    if (name[index] == key)
        return true;

    return isPresent(name, index + 1, key);
}
void indicesOfCharacter(string &name, int index, char &key, vector<int> &ans)
{
    if (index >= name.size())
        return;

    if (name[index] == key)
    {
        ans.push_back(index);
    }

    indicesOfCharacter(name, index + 1, key, ans);
}
void countOfChar(string &name, int index, char &key, int &count)
{
    if (index >= name.size())
        return;

    if (name[index] == key)
    {
        count = count + 1;
    }

    countOfChar(name, index + 1, key, count);
}
void printDigitsOfANumber(int &num)
{
    if (num <= 0)
        return;

    int newValue = num / 10;
    printDigitsOfANumber(newValue);

    int digit = num % 10;
    cout << digit;
}
int main()
{
    int arr[] = {-1, 9, 10, -14, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mini = arr[0];

    string name = "lovebabbar";
    char key = 'b';
    int count = 0;

    // int num = 0647; -> 0647 is an octal value, 423 in decimal
    int num = 983745;

    int len = name.size();

    system("cls");

    // Printing the array using recursion
    printArrayUsingRecursion(arr, n, 0);
    cout << "\n";

    // Printing the digits of a number using recursion
    if (num == 0)
    {
        cout << 0 << " ";
    }
    else
    {
        printDigitsOfANumber(num);
    }
    cout << "\n";

    // Finding the maximum number in an integer array using recursion
    cout << findMaxInArray(arr, n, 0, arr[0]);
    cout << "\n";

    // Finding the minimum number in an integer array using recursion
    finMinInArray(arr, n, 0, mini);
    cout << mini << "\n";

    // Finding the key in an array/string using recursion
    cout << "Is " << key << " present in " << name << " : " << isPresent(name, 0, key) << "\n";

    // Find how many times a key number is present in an array
    countOfChar(name, 0, key, count);
    cout << key << " is present " << count << " number of times."
         << "\n";

    // Find the index where the key number is present in an array
    vector<int> ans;
    indicesOfCharacter(name, 0, key, ans);
    for (int x : ans)
        cout << key << " is present at index : " << x << "\n";

    // lC#70 -> CLIMB STAIR -> https://leetcode.com/problems/climbing-stairs/description/

    return 0;
}