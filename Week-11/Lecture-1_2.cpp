// Reverse a string using stack
// Find the middle element in the stack
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
void findMiddleElementInStack(stack<int> &s, int &totalSize)
{
    if (s.empty())
    {
        cout << "Stack is empty!\n";
        return;
    }
    if (s.size() == (totalSize / 2) + 1)
    {
        cout << "Middle element of the stack is : " << s.top() << " ";
        return;
    }
    int temp = s.top();
    s.pop();
    findMiddleElementInStack(s, totalSize);
}
int main()
{
    system("cls");
    // stack<char> s;
    // string name = "Sagar Wadhwa";
    // string temp = "";

    // for (char x : name)
    // {
    //     s.push(x);
    // }
    // while (!s.empty())
    // {
    //     temp.push_back(s.top());
    //     s.pop();
    // }
    // cout << temp;

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int totalSize = s.size();
    findMiddleElementInStack(s, totalSize);
    return 0;
}