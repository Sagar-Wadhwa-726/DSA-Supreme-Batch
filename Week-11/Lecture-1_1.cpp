// Implementing two stacks in an array
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
using namespace std;
class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
    }

    void push1(int element)
    {
        if (top2 - top1 == 1 || top1 == size - 1)
        {
            cout << "Stack1 Overflow!\n";
            return;
        }
        arr[++top1] = element;
    }
    void push2(int element)
    {
        if (top2 - top1 == 1 || top2 == -1)
        {
            cout << "Stack2 Overflow!\n";
            return;
        }
        arr[--top2] = element;
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack1 Underflow!\n";
            return;
        }
        cout << arr[top1--] << " popped!\n";
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack2 Underflow!\n";
            return;
        }
        cout << arr[top2++] << " popped!\n";
    }
    int getTopStack1()
    {
        return arr[top1];
    }
    int getTopStack2()
    {
        return arr[top2];
    }
    bool isStack1Empty()
    {
        return top1 == -1 ? true : false;
    }
    bool isStack2Empty()
    {
        return top2 == size ? true : false;
    }
    void print()
    {

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    system("cls");
    Stack *s = new Stack(10);
    s->push2(1);
    s->push2(1);
    s->push2(1);
    s->push2(1);
    s->push2(1);
    s->push2(1);
    s->push2(1);
    s->push2(1);
    s->push2(1);
    s->push1(111);
    s->push1(111);
    s->push2(11);
    s->print();
    return 0;
}