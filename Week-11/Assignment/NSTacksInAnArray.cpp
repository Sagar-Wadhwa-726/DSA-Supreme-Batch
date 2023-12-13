#include <iostream>
#include <stack>
using namespace std;
class NSTack
{
    int *a, *top, *next; // main array, top array, next array
    int n;               // number of stacks
    int size;            // size of the main array
    int freespot;        // tells free space in main array
public:
    NSTack(int n, int size)
    {
        freespot = 0;
        this->n = n;
        this->size = size;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
            top[i] = -1;
        for (int i = 0; i < size; i++)
            next[i] = i + 1;
        next[size - 1] = -1;
    }

    bool push(int x, int m)
    {
        if (freespot == -1)
            return false;
        int index = freespot;
        freespot = next[index];
        a[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;
        int index = top[m - 1];
        top[m - 1] = next[index];
        int poppedElement = a[index];
        next[index] = freespot;
        freespot = index;
        return poppedElement;
    }

    ~NSTack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};
int main()
{
    system("cls");
    NSTack s(3, 6);
    cout << s.push(10, 1) << "\n";
    cout << s.push(10, 1) << "\n";
    cout << s.push(10, 1) << "\n";
    cout << s.push(14, 2) << "\n";
    cout << s.push(15, 3) << "\n";
    cout << s.pop(1) << "\n";
    cout << s.pop(2) << "\n";
    return 0;
}
