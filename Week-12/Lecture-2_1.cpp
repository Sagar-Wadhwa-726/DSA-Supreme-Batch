#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseFirstKElementsOfQueue(queue<int> &q, int k)
{
    int n = q.size();

    if (k <= 0 || k > n)
        return;
    stack<int> s;
    int count = 0;
    while (count < k)
    {
        s.push(q.front());
        q.pop();
        count++;
    }
    count = 0;
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    count = 0;
    while (count < n - k && n - k != 0)
    {
        count++;
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}
void interleaveQueue(queue<int> &q)
{
    if (q.empty())
        return;
    // take a temporary queue of size n/2
    int n = q.size();
    queue<int> temp;
    int count = 0;
    while (count < n / 2)
    {
        temp.push(q.front());
        q.pop();
        count++;
    }
    while (!temp.empty() && !q.empty())
    {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
    if (n & 1)
    {
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    system("cls");
    queue<int> q;
    q.push(3);
    q.push(5);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    int k = 3;

    // printing the elements of the queue
    reverseFirstKElementsOfQueue(q, k);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    // interleaving queue
    queue<int> qq;
    qq.push(10);
    qq.push(20);
    qq.push(30);
    qq.push(40);
    qq.push(50);
    qq.push(60);
    qq.push(70);
    qq.push(80);
    qq.push(90);
    interleaveQueue(qq);
    cout << "\n";
    while (!qq.empty())
    {
        cout << qq.front() << " ";
        qq.pop();
    }
    return 0;
}