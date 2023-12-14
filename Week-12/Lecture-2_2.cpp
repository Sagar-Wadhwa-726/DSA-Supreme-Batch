#include <iostream>
#include <queue>
#include <deque>
using namespace std;
void solve(int arr[], int size, int k)
{
    deque<int> q;

    // Process first window of size "k"
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push_back(i);
    }
    // process the remaining window
    for (int i = k; i < size; i++)
    {
        // find the answer of the previous window
        if (q.empty())
            cout << 0 << " ";
        else
            cout << arr[q.front()] << " ";

        // remove the elements which are out of the window
        while (!q.empty() && (i - q.front() >= k))
            q.pop_front();
        // check current element for insertion
        if (arr[i] < 0)
            q.push_back(i);
    }
    // we need to print the window of the old answer, since firstly the answer of the old window is printed and then the current window is processed so for the last window the answer of the previous window will be printed and current window will be processed but for the next iteration we will come out of the loop and will not be able to print the answer of the last window
    if (q.empty())
        cout << 0 << " ";
    else
        cout << arr[q.front()];
}
int main()
{
    system("cls");
    // Finding the first negative number in every window of size 'k'
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;
    int k = 3;

    solve(arr, size, k);
    return 0;
}