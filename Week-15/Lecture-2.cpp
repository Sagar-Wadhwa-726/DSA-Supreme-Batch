#include <iostream>
#include <queue>
using namespace std;
/*Function which returns the kth greatest element*/
int getKthGreatestElement(int arr[], int &n, int &k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);
    for (int i = k; i < n; i++)
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }

    return pq.top();
}
/*Function which returns the kth smallest element*/
int getKthSmallestElement(int arr[], int &n, int &k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);
    for (int i = k; i < n; i++)
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }

    return pq.top();
}
int main()
{
    system("cls");
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 5;
    int ans = getKthSmallestElement(arr, n, k);
    cout << ans << "\n";

    ans = getKthGreatestElement(arr, n, k);
    cout << ans << "\n";
    return 0;
}