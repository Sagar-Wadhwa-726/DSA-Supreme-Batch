#include <iostream>
#include <vector>
using namespace std;
class KQueues
{
public:
    int n, k, freespot;
    int *arr, *front, *rear, *next;
    KQueues(int _n, int _k) : n(_n), k(_k), freespot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;

        for (int i = 0; i < n; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
    }

    bool push(int x, int qi)
    {
        // check for overflow
        if (freespot == -1)
            return false;

        // Find first free index
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // if this is the first element of q1
        if (front[qi] == -1)
            front[qi] = index;
        // link new element to that queues rearest element
        else
            next[rear[qi]] = index;
        // update next
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    int pop(int qi)
    {
        // check for underflow
        if (front[qi] == -1)
            return -1;

        // find index to pop
        int index = front[qi];

        // update front
        front[qi] = next[index];

        // update freespot
        next[index] = freespot;
        freespot = index;

        // return the popped element
        return arr[index];
    }

    ~KQueues()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};
int main()
{
    system("cls");
    KQueues *obj = new KQueues(8, 3);
    cout << obj->push(1, 0) << "\n";
    cout << obj->push(2, 0) << "\n";
    cout << obj->push(5, 1) << "\n";
    cout << obj->push(3, 0) << "\n";
    cout << obj->pop(1) << "\n";
    cout << obj->pop(1) << "\n";
    cout << obj->pop(0) << "\n";
    cout << obj->pop(0) << "\n";
    cout << obj->pop(0) << "\n";
    cout << obj->pop(0) << "\n";
    cout << obj->pop(0) << "\n";
    cout << obj->pop(1) << "\n";
    return 0;
}