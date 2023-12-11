#include <iostream>
#include <stack>
#include <limits>
using namespace std;

/*Custom made stack*/
class Stack
{
private:
    int *arr;
    int size;
    int top;

public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << arr[top--] << " popped!\n";
    }

    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = element;
    }

    int getTop()
    {
        if (top == -1)
            return INT8_MIN;
        return arr[top];
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
};
int main()
{
    system("cls");
    Stack *s = new Stack(5);
    if (s->isEmpty())
        cout << "Stack is empty!\n";
    else
        cout << "Stack is not empty!\n";

    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->push(6);

    if (s->isEmpty())
        cout << "Stack is empty!\n";
    else
        cout << "Stack is not empty!\n";

    cout << "Stack size : " << s->getSize() << "\n";
    while (!s->isEmpty())
    {
        cout << s->getTop() << " ";
        s->pop();
    }
    cout << "Stack size : " << s->getSize() << "\n";

    s->push(999);
    cout << s->getTop() << "\n";

    cout << "Stack size : " << s->getSize() << "\n";
    s->pop();
    s->pop();
    cout << s->getTop();
    return 0;
}