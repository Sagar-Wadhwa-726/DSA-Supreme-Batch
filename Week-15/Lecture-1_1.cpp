#include <iostream>
using namespace std;
/*Function to heapify an array*/
void heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex <= n && arr[largest] < arr[leftIndex])
        largest = leftIndex;
    if (rightIndex <= n && arr[largest] < arr[rightIndex])
        largest = rightIndex;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}

/*Function to build a heap*/
void buildheap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);
}

/*Function to perform heap sort*/
void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n--]);
        heapify(arr, n, 1);
    }
}
int main()
{
    system("cls");
    int arr[] = {-1, 100, 50, 60, 30, 20};
    int n = 5;
    buildheap(arr, 5);

    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";

    heapSort(arr, n);
    cout << "\n";
    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";

    return 0;
}