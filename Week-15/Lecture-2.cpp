#include <iostream>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
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

/*Function to check if a binary tree is a heap of not*/
pair<bool, int> checkIfHeapOrNot(Node *&root)
{
    // base case
    if (!root)
        return {true, INT_MIN};
    if (!root->left && !root->right)
        return {true, root->data};

    pair<bool, int> leftAns = checkIfHeapOrNot(root->left);
    pair<bool, int> rightAns = checkIfHeapOrNot(root->right);

    if (leftAns.first && rightAns.first && root->data > leftAns.second && root->data > rightAns.second)
        return {true, root->data};
    else
        return {false, root->data};
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