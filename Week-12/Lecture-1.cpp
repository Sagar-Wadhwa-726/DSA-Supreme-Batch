#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <queue>
using namespace std;
class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void push(int val)
    {
        if (rear == size)
        {
            cout << "Queue is full !\n";
            return;
        }
        arr[rear++] = val;
    }
    int pop()
    {
        if (front == rear)
        {
            cout << "Queue is already empty !\n";
            return -1;
        }
        int val = arr[front];
        arr[front++] = -1;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        return val;
    }
    int getSize()
    {
        return rear - front;
    }
    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is empty! \n";
            return -1;
        }
        return arr[front];
    }
    bool isEmpty()
    {
        return rear == front;
    }
};
int main()
{
    system("cls");
    Queue q(10);
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    cout << "Size of queue is : " << q.getSize() << "\n";
    q.pop();
    cout << "Size of queue is : " << q.getSize() << "\n";
    cout << "Element at front is : " << q.getFront() << "\n";
    if (q.isEmpty())
    {
        cout << "Queue is empty!\n";
    }
    else
    {
        cout << "Queue is not empty!\n";
    }
    return 0;
}