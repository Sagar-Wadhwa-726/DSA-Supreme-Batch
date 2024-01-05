#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Normal recursive code, gives TLE
TC - EXPONENTIAL
SC - O(N)
Can be solved using 1D DP, because only 1 variable is being changed (n)
*/
int solveUsingRecursion(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    return (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);
}

/*1D DP TOP DOWN APPROACH
Here in this recursive approach the recursive calls are being made only once
hence the time complexity is linear O(N) and the space complexity is O(N)+O(N) = o(N)
space is being taken for dp array and also for recursive calls*/
int solveUsingMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (solveUsingMemo(n - 2, k, dp) + solveUsingMemo(n - 1, k, dp)) * (k - 1);
    return dp[n];
}

/*1D DP BOTTOM UP APPROACH
In the tabulation method the bottom up approach is being followed where the time complexity is linear
O(N) and the space complexity is just being taken for the dp array and not for the recursive call stack
space. Hence SC = O(N)*/
int solveusingTab(int n, int k)
{
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    return dp[n];
}

/*Space optimization approach where dp[i] depends on dp[i-2] and dp[i-1]
Time complexity will be O(N) and SC = O(1)*/
int solveUsingSpaceOptimization(int n, int k)
{
    int prev1 = k * k;
    int prev2 = k;
    int curr = 0;

    for (int i = 3; i <= n; i++)
    {
        curr = (prev2 + prev1) * (k - 1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

/*Recursive code for 0/1 knapsack problem to maximize profit. This follows the pick/notpick pattern
(subsequence pattern). Here n is representing the index as we are moving from right to left. We can also
move from left to right i.e. we can start from 0th index also. (not applicable for space optimizatoin).
Prefer right to left moving. TC= EXPONENTIAL, SC = O(N*M)*/
int knapsackRecursive(int weight[], int value[], int index, int capacity)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        return 0;
    }

    // either we can include the current item basis on the condition only if the current item weight is
    // not greater than the capacity of the knopsack
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + knapsackRecursive(weight, value, index - 1, capacity - weight[index]);

    // or we can exclude the current item
    int exclude = knapsackRecursive(weight, value, index - 1, capacity);

    return max(include, exclude);
}

/*Since index and capacity both change in the recursive code, this will be a 2D DP
The time complexity for this would be linear O(N*M) n= number of items and M is the capacity since we are making the recursive calls only once and the space complexity will be for dp array and call stack which will O(N*M)+O(N*M) = O(N*M)*/
int knapsackTopDown(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // either we can include the current item basis on the condition only if the current item weight is
    // not greater than the capacity of the knopsack
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + knapsackTopDown(weight, value, index - 1, capacity - weight[index], dp);

    // or we can exclude the current item
    int exclude = knapsackTopDown(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

/*0/1 KNAPSACK using bottom up approach (tabulation method).Time complexity - O(N*M)
SC = for 2D dp array O(N*M)*/
int knapsackBottomUp(int weight[], int value[], int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index <= n - 1; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + dp[index - 1][wt - weight[index]];

            int exclude = dp[index - 1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

/*0/1 KNAPSACK using first space optimization appraoch where every row depends on the previous row
SC = for 2 1D arrays = O(M) where M represents the capacity
TC = O(N*M)*/
int knapsackSpaceOptimizationOne(int weight[], int value[], int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);
    vector<int> prev(capacity + 1, 0); // initially assumed to be the 0th row

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for (int index = 1; index <= n - 1; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + prev[wt - weight[index]];

            int exclude = prev[wt];

            curr[wt] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}

/*0/1 KNAPSACK using second space optimization appraoch where
SC = for one array O(M), TC = O(N*M)*/
int knapsackSpaceOptimizationTwo(int weight[], int value[], int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    for (int index = 1; index <= n - 1; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + curr[wt - weight[index]];

            int exclude = curr[wt];

            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}
int main()
{
    system("cls");

    //  PAINTING FENCE - NORMAL RECURSION
    // int n = 4;
    // int k = 3;
    // int ans = solveUsingRecursion(n, k);
    // cout << ans;

    //  PAINTING FENCE - TOP DOWN APPROACH
    // int n = 4;
    // int k = 3;
    // vector<int> dp(n + 1, -1);
    // int ans = solveUsingMemo(n, k, dp);
    // cout << ans;

    //  PAINTING FENCE - BOTTOM UP APPROACH
    // int n = 4;
    // int k = 3;
    // int ans = solveusingTab(n, k);
    // cout << ans;

    //  PAINTING FENCE -  SPACE OPTIMIZATION APPROACH
    // int n = 4;
    // int k = 3;
    // int ans = solveUsingSpaceOptimization(n, k);
    // cout << ans;

    /*Profit/Weight approach does not work here, the code will break*/
    // 0/1 KNAPSACK PROBLEM USING SIMPLE RECURSION
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // int ans = knapsackRecursive(weight, value, n - 1, capacity);
    // cout << ans;

    // 0/1 KNAPSACK PROBLEM USING TOP DOWN 2D DP
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = knapsackTopDown(weight, value, n - 1, capacity, dp);
    // cout << ans;

    // // 0/1 KNAPSACK PROBLEM USING BOTTOM UP 2D DP
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // int ans = knapsackBottomUp(weight, value, n, capacity);
    // cout << ans;

    // 0/1 KNAPSACK PROBLEM USING SPACE OPTIMIZATION FIRST APPROACH (USING 2 1D ARRAYS)
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // int ans = knapsackSpaceOptimizationOne(weight, value, n, capacity);
    // cout << ans;

    // 0/1 KNAPSACK PROBLEM USING SPACE OPTIMIZATION SECOND APPROACH (USING ONLY ONE ARRAY)
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;
    int ans = knapsackSpaceOptimizationTwo(weight, value, n, capacity);
    cout << ans;
    return 0;
}