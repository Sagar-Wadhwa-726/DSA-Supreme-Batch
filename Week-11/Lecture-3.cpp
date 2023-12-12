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
int main()
{
    system("cls");
    // MIN STACK QUESTION ON LEETCODE
    // https://leetcode.com/problems/min-stack/description/

    // LONGEST VALID PARENTHESIS QUESTION ON LEETCODE
    // https://leetcode.com/problems/longest-valid-parentheses/

    // NEXT LARGER ELEMENT - O(N)
    vector<int> v{2, 1, 4, 3};
    vector<int> ans(v.size());

    stack<int> s;
    s.push(-1); // by default next larger element for the last element

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (s.top() >= v[i])
            s.pop();
        ans[i] = s.top();
        s.push(v[i]);
    }
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}