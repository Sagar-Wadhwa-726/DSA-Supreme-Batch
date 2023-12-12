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
void previousSmallerElement(vector<int> &v, vector<int> &prevSmallerArray)
{
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < v.size(); i++)
    {
        // C2: Compare element with an element and not an index with element
        while (s.top() != -1 && v[s.top()] >= v[i])
            s.pop();
        prevSmallerArray[i] = s.top();
        // C1: insert index instead of the actual element
        s.push(i);
    }
}
void nextSmallerElement(vector<int> &v, vector<int> &nextSmallerArray)
{
    stack<int> s;
    s.push(-1);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        // C2: Compare element with an element and not an index with element
        while (s.top() != -1 && v[s.top()] >= v[i])
            s.pop();
        nextSmallerArray[i] = s.top();
        // C1: insert index instead of the actual element
        s.push(i);
    }
}
int getRectangularAreaHistorgram(vector<int> &heights)
{
    vector<int> prevSmaller(heights.size());
    vector<int> nextSmaller(heights.size());

    previousSmallerElement(heights, prevSmaller);
    nextSmallerElement(heights, nextSmaller);
    int maxArea = -1;
    for (int i = 0; i < heights.size(); i++)
    {
        if (nextSmaller[i] == -1)
            nextSmaller[i] = heights.size();
        maxArea = max(maxArea, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
    }

    return maxArea;
}
int main()
{
    system("cls");
    // Finding the previous smaller element
    // vector<int> v{2, 1, 4, 3};
    // vector<int> ans(v.size());
    // stack<int> s;
    // s.push(-1);
    // previousSmallerElement(v, ans, s);
    // for (int x : ans)
    //     cout << x << " ";

    // https://leetcode.com/problems/largest-rectangle-in-histogram/
    vector<int> heights{2, 1, 5, 6, 2, 3};
    cout << "Max Area is : " << getRectangularAreaHistorgram(heights);
    return 0;
}