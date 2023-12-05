#include <iostream>
#include <vector>
using namespace std;

/*Function which prints the vector elements*/
void printVectorElements(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

/*Function which finds the smallest element from the array and returns its index*/
int smallestElementIndex(vector<int> &arr, int start)
{
    int minElementIndex = start;
    for (int i = start + 1; i < arr.size(); i++)
        if (arr[i] < arr[minElementIndex])
            minElementIndex = i;
    return minElementIndex;
}

/*Function which performs selection sort*/
void selectionSort(vector<int> &arr)
{
    // The main aim of the selection sort is to select the smallest element from the array and
    // place it at it's correct position
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minElementIndex = smallestElementIndex(arr, i);
        int temp = arr[minElementIndex];
        arr[minElementIndex] = arr[i];
        arr[i] = temp;
    }
}

/*Function which performs bubble sort*/
void bubbleSort(vector<int> &arr)
{
    bool isSorted = true;
    for (int i = 1; i < arr.size(); i++)
    {
        // Main aim of bubble sort is to repeatedly swap two adjacent elements if they are at the
        // wrong position
        for (int j = 0; j < arr.size() - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
            break;
        else
            isSorted = true;
    }
}

/*Function which performs insertion sort*/
void insertionSort(vector<int> &arr)
{
    // The main aim of the insertion sort algorithm is to insert an element from the unsorted array into the sorted array at its
    // correct position. Assume the first element to be sorted.
    for (int i = 1; i < arr.size(); i++)
    {
        int index = i - 1;
        int temp = arr[i];
        while (index >= 0 && arr[index] > temp)
            arr[index + 1] = arr[index--];
        arr[++index] = temp;
    }
}

int main()
{
    system("cls");
    vector<int> arr{1, 6, 0, -3, 6, 12, -6};

    /*SELECTION SORT*/
    // cout << "Array before sorting is : ";
    // printVectorElements(arr);
    // selectionSort(arr);
    // cout << "Array after sorting is : ";
    // printVectorElements(arr);

    /*BUBBLE SORT*/
    // cout << "Array before sorting is : ";
    // printVectorElements(arr);
    // bubbleSort(arr);
    // cout << "Array after sorting is : ";
    // printVectorElements(arr);

    /*INSERTION SORT*/
    cout << "Array before sorting is : ";
    printVectorElements(arr);
    insertionSort(arr);
    cout << "Array after sorting is : ";
    printVectorElements(arr);
    return 0;
}
