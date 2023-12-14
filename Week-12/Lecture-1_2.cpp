#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits>
#include <stack>
#include <deque>
using namespace std;
class Dequeue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void pushRear(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear = front - 1))
        {
            cout << "Queue is already full!\n";
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = val;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        else
            arr[++rear] = val;
    }
    void pushFront(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear = front - 1))
        {
            cout << "Queue is already full!\n";
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = val;
        }
        else
        {
            arr[--front] = val;
        }
    }
    int popRear()
    {
        if ((front == -1 && rear == -1) || (rear == front - 1))
        {
            cout << "Queue is empty !\n";
        }
        else if (front == rear)
        {
            int val = arr[front];
            front = -1;
            rear = -1;
            return val;
        }
        else if (rear == 0)
        {
            int val = arr[rear];
            rear = size - 1;
            return val;
        }
        else
        {
            return arr[rear--];
        }
    }
    int popFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        else if (front == rear)
        {
            int val = arr[front];
            front = -1;
            rear = -1;
            return val;
        }
        else if (front == size - 1)
        {
            int val = arr[front];
            front = 0;
            return val;
        }
        else
        {
            return arr[front++];
        }
    }
};
int main()
{
    system("cls");
    // Dequeue q(10);
    // #include<dequeue>, we can use stl also
    deque<int> q;
    q.push_front(5);
    q.push_front(10);
    q.push_back(20);
    q.push_back(30);
    cout << "size of dequeue is : " << q.size() << "\n";
    q.pop_front();
    cout << "size of dequeue is : " << q.size() << "\n";
    q.pop_back();
    cout << "size of dequeue is : " << q.size() << "\n";
    cout << "front of dequeue is : " << q.front() << "\n";
    cout << "back of dequeue is : " << q.back() << "\n";
    if (q.empty())
    {
        cout << "dequeue is empty !\n";
    }
    else
    {
        cout << "dequeue is not empty !\n";
    }
    return 0;
}