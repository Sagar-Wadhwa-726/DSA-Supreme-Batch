#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearch(vector<int> &arr, int s, int e, int x)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
}
int expSearch(vector<int> &arr, int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (i < arr.size() && arr[i] <= x)
        i *= 2;
    int n = arr.size();
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}
int main()
{
    system("cls");
    vector<int> arr{3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int x = 13;
    int ans = expSearch(arr, x);
    cout << x << " is present at index : " << ans;
    return 0;
}