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
#include <deque>
#include <stack>
using namespace std;
class Solution
{
public:
    int sumOfMinMaxOfAllWindowOfSizeK(vector<int> &nums, int k)
    {
        int ans = 0;
        deque<int> dq, dq2;
        // Process the first window of size k
        for (int i = 0; i < k; i++)
        {
            // remove all the elements less than the current element
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            // remove all the elements greater than the current element
            while (!dq2.empty() && nums[i] <= nums[dq2.back()])
                dq2.pop_back();
            // insert the index to remove the out of the window elements
            dq.push_back(i);
            dq2.push_back(i);
        }

        ans += nums[dq.front()] + nums[dq2.front()];
        // process the remaining window
        for (int i = k; i < nums.size(); i++)
        {
            // remove the elements out of the window
            if (!dq.empty() && i - dq.front() >= k)
                dq.pop_front();

            if (!dq2.empty() && i - dq2.front() >= k)
                dq2.pop_front();

            // for the current element remove all the elements less than the current element
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            // for the current element remove all the elements greater than the current element
            while (!dq2.empty() && nums[i] <= nums[dq2.back()])
                dq2.pop_back();

            // push the current element
            dq.push_back(i);
            dq2.push_back(i);

            // store the answer of the current windo
            ans += nums[dq.front()] + nums[dq2.front()];
        }
        return ans;
    }
};
int main()
{
    system("cls");
    vector<int> v{2, 5, -1, 7, -3, -1, 2};
    int k = 4;
    Solution *s = new Solution();
    cout << s->sumOfMinMaxOfAllWindowOfSizeK(v, k);
    return 0;
}