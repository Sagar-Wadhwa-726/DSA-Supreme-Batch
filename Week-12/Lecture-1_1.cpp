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
#include <queue>
using namespace std;
class CircularQueue
{
public:
    int size;
    int front;
    int rear;
    int *arr;
    CircularQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void push(int data)
    {
        // overflow condition
        if ((rear == size - 1 && front == 0) || (rear == front - 1))
        {
            cout << "Queue is full!\n";
            return;
        }
        // first element condition
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        // circular nature
        else if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = data;
        }
        // normal case
        else
        {
            arr[rear++] = data;
        }
    }
    int pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty !\n";
            return;
        }
        // single element case
        else if (front == rear)
        {
            int val = arr[front];
            front = -1;
            rear = -1;
            return val;
        }
        // circular nature
        else if (front == size - 1)
        {
            int val = arr[front];
            front = 0;
            return val;
        }
        // normal flow
        else
        {
            return arr[++front];
        }
    }
};
int main()
{
    system("cls");
    CircularQueue q(10);
    return 0;
}