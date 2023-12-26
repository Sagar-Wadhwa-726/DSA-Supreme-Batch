#include <iostream>
#include <queue>
using namespace std;
/*Custom data type to store this in a heap instead of just an integer value*/
class Info
{
public:
    int value; // integer value
    int row;   // from which array this number belongs to
    int col;   // from which index this number belongs to of that array

    Info(int _value, int _row, int _col) : value(_value), row(_row), col(_col) {}
};

/*Custom comparator which gives priority to that data of type Info* of which the value is minimum*/
class custom_comparator
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->value > b->value;
    }
};

/*Function which returns a resultant array after merging k arrays*/
vector<int> mergeKSortedArrays(int arr[][4], int &k, int &n)
{
    vector<int> ans;
    priority_queue<Info *, vector<Info *>, custom_comparator> minHeap;

    // Insert the first element of every array
    for (int i = 0; i < k; i++)
    {
        Info *temp = new Info(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    while (!minHeap.empty())
    {
        // Insert the top element of the min heap in the ans vector
        Info *temp = minHeap.top();
        minHeap.pop();
        int topElement = temp->value;
        int topRow = temp->row;
        int topCol = temp->col;
        ans.push_back(topElement);

        // Now insert a new Info type data in the heap if available
        if (topCol + 1 < n)
        {
            Info *newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(newInfo);
        }
    }
    return ans;
}
int main()
{
    system("cls");
    int arr[][4] = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}};
    int k = 3;
    int n = 4;
    vector<int> ans = mergeKSortedArrays(arr, k, n);
    for (auto x : ans)
        cout << x << " ";

    // MERGE K SORTED LINKED LIST QUESTION ON LEETCODE
    // https://leetcode.com/submissions/detail/1128696478/

    // Smallest Range Covering Elements from K Lists
    // https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
    return 0;
}