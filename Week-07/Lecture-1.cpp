#include <iostream>
using namespace std;
void reverseCounting(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    reverseCounting(n - 1);
}
void normalCounting(int n)
{
    if (n == 0)
    {
        return;
    }
    normalCounting(n - 1);
    cout << n << " ";
}
long long int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int powerFunction(int base, int power)
{
    if (power == 0)
        return 1;
    return base * powerFunction(base, power - 1);
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    system("cls");

    // Reverse counting from n->1
    reverseCounting(5);
    cout << "\n";

    // Normal counting from 1->n
    normalCounting(5);
    cout << "\n";

    // Finding factorial using recursion
    cout << factorial(5);
    cout << "\n";

    // Printing the nth term of a fibonacci series
    cout << fib(6);
    cout << "\n";

    // Finding the power of a base
    cout << powerFunction(2, 5);
    cout << "\n";

    return 0;
}