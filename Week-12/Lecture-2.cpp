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
#include <queue>
using namespace std;
void reverseQueue(queue<int> &q)
{
    if (q.empty())
        return;

    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}
int main()
{
    system("cls");
    // Q1: Reverse a queue
    // approach 1 - pop from queue, push in stack, pop from stack, push in queue
    stack<int> st;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // while (!q.empty())
    // {
    //     st.push(q.front());
    //     q.pop();
    // }
    // while (!st.empty())
    // {
    //     q.push(st.top());
    //     st.pop();
    // }
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    // approach 2 - using recursion
    reverseQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}