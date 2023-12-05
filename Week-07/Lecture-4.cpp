#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>
#include <vector>
#include <limits>
#include <string>
using namespace std;
int minimumNumberOfElementsRequiredToFormTheTargetSum(vector<int> &arr, int target)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = minimumNumberOfElementsRequiredToFormTheTargetSum(arr, target - arr[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}
int minimumNumberOfElementsRequiredToFormTheTargetSumVersion2(vector<int> &arr, int &target, int sum)
{
    if (target == sum)
        return 0;
    if (target < sum)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = minimumNumberOfElementsRequiredToFormTheTargetSumVersion2(arr, target, sum + arr[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}
int cutIntoSegments(int n, int x, int y, int z)
{
    // Base case
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    int ans1 = cutIntoSegments(n - x, x, y, z) + 1;
    int ans2 = cutIntoSegments(n - y, x, y, z) + 1;
    int ans3 = cutIntoSegments(n - z, x, y, z) + 1;

    return max(ans1, max(ans2, ans3));
}
void maxSumOfNonAdjacentElements(vector<int> &arr, int index, int sum, int &maxi)
{
    // Base case
    if (index >= arr.size())
    {
        maxi = max(sum, maxi);
        return;
    }

    // IF INCLUDING THE CURRENT ELEMENT
    maxSumOfNonAdjacentElements(arr, index + 2, sum + arr[index], maxi);

    // IF EXCLUDING THE CURRENT ELEMENT
    maxSumOfNonAdjacentElements(arr, index + 1, sum, maxi);
}
int main()
{
    system("cls");

    vector<int> arr{1, 2, 3};
    int target = 5;

    vector<int> arr2{2, 1, 4, 9};
    int maxi = INT_MIN;

    // https://leetcode.com/problems/coin-change/description/
    // Minimum number of elements required to form the target sum
    int ans = minimumNumberOfElementsRequiredToFormTheTargetSum(arr, target);
    cout << "Minimum number of elements required to form " << target << " is : " << ans;
    cout << "\n";

    // https://leetcode.com/problems/coin-change/description/
    // Minimum number of elements required to form the target sum - Version 2
    int ans2 = minimumNumberOfElementsRequiredToFormTheTargetSumVersion2(arr, target, 0);
    cout << "Minimum number of elements required to form (V2) " << target << " is : " << ans2;
    cout << "\n";

    // Cut into segments question
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int solution = cutIntoSegments(n, x, y, z);
    if (solution < 0)
        solution = 0;
    cout << "Answer is : " << solution << "\n";

    // Maximum sum of non adjacent elements
    maxSumOfNonAdjacentElements(arr2, 0, 0, maxi);
    cout << "Maximum sum of non adjacent elements is : " << maxi;
    return 0;
}