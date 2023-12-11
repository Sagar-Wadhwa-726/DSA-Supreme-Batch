#include <iostream>
#include <stack>
using namespace std;
/*Function to insert an element at the bottom of the stack*/
void insertAtBottom(stack<int> &s, int &target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int temp;
    if (!s.empty())
    {
        temp = s.top();
    }
    else
    {
        cout << "Stack became empty, can't insert at bottom !\n";
        return;
    }
    s.pop();
    insertAtBottom(s, target);
    s.push(temp);
}
/*Function to reverse a stack*/
void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
        return;

    // solve one case
    int temp = s.top();
    s.pop();
    reverseStack(s);
    // rest will be handled by recursion
    insertAtBottom(s, temp);
}
/*Function to insert an element an a sorted stack in a sorted manner*/
void insertSorted(stack<int> &s, int &target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    if (s.top() >= target)
    {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, target);
    s.push(temp);
}
/*Function to sort a stack*/
void sortStack(stack<int> &s)
{
    if (s.empty())
        return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, temp);
}
int main()
{
    system("cls");
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    // int target = 11;
    // insertAtBottom(s, target);
    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    // reverseStack(s);

    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    // REMOVE REDUNDANT PARENTHESIS QUESTION

    return 0;
}