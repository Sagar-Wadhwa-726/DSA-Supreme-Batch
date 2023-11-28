// https://www.spoj.com/problems/EKO/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<long long int> &trees, long long int m, long long int sol)
{
    // Variable to store the amount of wood collected till now
    long long int woodCollected = 0;
    for (long long int i = 0; i < trees.size(); i++)
    {
        // only then wood can be collected
        if (trees[i] > sol)
        {
            woodCollected += trees[i] - sol;
        }
    }
    return woodCollected >= m ? true : false;
}

long long int maxSawbladeHeight(vector<long long int> &trees, long long int m)
{
    long long int start = 0, end, ans = -1;
    end = *max_element(trees.begin(), trees.end());

    while (start <= end)
    {
        long long int mid = start + ((end - start) >> 2);
        if (isPossibleSolution(trees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) >> 2;
    }
    return ans;
}

int main()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> trees;
    while (n--)
    {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }
    cout << maxSawbladeHeight(trees, m) << endl;
    return 0;
}