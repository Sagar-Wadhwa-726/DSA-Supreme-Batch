#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[101];
    int size;
    Heap()
    {
        size = 0;
    }

    /*Function to insert a value in the heap*/
    void insert(int value)
    {
        // place the value at the end of the array
        size = size + 1;
        int index = size;
        arr[index] = value;

        // now place the value at the correct position
        while (index > 1)
        {
            if (arr[index] > arr[index / 2])
            {
                swap(arr[index], arr[index / 2]);
                index = index / 2;
            }
            else
                break;
        }
    }

    /*Function to delete a value from the heap*/
    int deleteValue()
    {
        int ans = arr[1];
        // replace top node value with the last node value
        arr[1] = arr[size];
        size--;

        // place the root node at the correct position
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;
            if (left < size && arr[largest] < arr[left])
                largest = left;
            if (right < size && arr[largest] < arr[right])
                largest = right;
            if (largest == index)
                break;
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};
int main()
{
    system("cls");
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    for (int i = 0; i <= h.size; i++)
        cout << h.arr[i] << " ";

    h.insert(110);

    for (int i = 0; i <= h.size; i++)
        cout << h.arr[i] << " ";

    return 0;
}