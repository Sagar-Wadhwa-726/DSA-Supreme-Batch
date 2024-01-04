#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Revised Dp - lecture 3
int solveusingrecursion(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k + (k * (k - 1));

    return ((solveusingrecursion(n - 2, k) + solveusingrecursion(n - 1, k)) * (k - 1));
}

int solveusingmem(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k + (k * (k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = ((solveusingmem(n - 2, k, dp) + solveusingmem(n - 1, k, dp)) * (k - 1));
    return dp[n];
}

int solveusingtab(int n, int k)
{
    vector<int> dp(n + 1, -1);

    dp[1] = k;
    dp[2] = k + (k * (k - 1));

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    return dp[n];
}

int solveusingspaceoptimization(int n, int k)
{

    int prev1 = k + (k * (k - 1));
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

int knapsackrec(int weight[], int value[], int index, int capacity)
{
    /* n->index of last element, renamed to index*/
    // base case -> only 1 item left
    if (index - 1 == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        return 0;
    }

    // including the current item, if possible
    int include = 0;
    if (weight[index - 1] <= capacity)
        include = value[index - 1] + knapsackrec(weight, value, index - 1, capacity - value[index - 1]);

    // excluding the current item
    int exclude = knapsackrec(weight, value, index - 1, capacity);

    return max(include, exclude);
}

int knapsackMEMO(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    if (index - 1 == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        return 0;
    }

    if (dp[index - 1][capacity] != -1)
        return dp[index - 1][capacity];

    int include = 0;
    if (weight[index - 1] <= capacity)
        include = value[index - 1] + knapsackMEMO(weight, value, index - 1, capacity - weight[index - 1], dp);

    int exclude = knapsackMEMO(weight, value, index - 1, capacity, dp);

    dp[index - 1][capacity] = max(include, exclude);
    return dp[index - 1][capacity];
}

int knapsackTAB(int weight[], int value[], int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // base case for index=0 -> row number 0, and traverse every column of this row
    // which is capacity in dp array
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    // in top down index goes from m-1 till 0 , capacity->0
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

int knapsackSO(int weight[], int value[], int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    // in top down index goes from m-1 till 0 , capacity->0
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
        // shift
        prev = curr;
    }
    return prev[capacity];
}

int knapsackSO2(int weight[], int value[], int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    // in top down index goes from m-1 till 0 , capacity->0
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

    // Q1: https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

    // USING RECURSION
    // int n = 4;
    // int k = 3;
    // int ans = solveusingrecursion(n, k);
    // cout << ans;

    // USING TOP DOWN APPROACH
    // int n = 4;
    // int k = 3;
    // vector<int> dp(n + 1, -1);
    // int ans = solveusingmem(n, k, dp);
    // cout << ans;

    // USING BOTTOM UP APPROACH
    // int n = 4;
    // int k = 3;
    // int ans = solveusingtab(n, k);
    // cout << ans;

    // USING SPACE OPTIMIZATION APPROACH
    // int n = 4;
    // int k = 3;
    // int ans = solveusingspaceoptimization(n, k);
    // cout << ans;

    // 0/1 KNAPSACK INCLUDE EXCLUDE PATTERN APPROACH
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // int ans = knapsackrec(weight, value, n, capacity);
    // cout << ans;

    // 0/1 knapsack using 2D DP TOP DOWN APPROACH
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = knapsackMEMO(weight, value, n, capacity, dp);
    // cout << ans;

    // 0/1 knapsack using 2D DP BOTTOM UP APPROACH
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // int ans = knapsackTAB(weight, value, n, capacity);
    // cout << ans;

    // 0/1 knapsack using 2D DP USING SPACE OPTIMIZATION APPROACH
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int n = 3;
    // int capacity = 4;
    // int ans = knapsackSO(weight, value, n, capacity);
    // cout << ans;

    // 0/1 knapsack using 2D DP USING SPACE OPTIMIZATION APPROACH - 2
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;
    int ans = knapsackSO2(weight, value, n, capacity);
    cout << ans;
    return 0;
}