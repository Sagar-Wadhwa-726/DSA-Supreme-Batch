// Give special attention to the character arrays and pointers
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <malloc.h>
#include <math.h>
using namespace std;
void solve(int *p)
{
    cout << "\nSize of the array is : " << sizeof(p);
}
int main()
{
    system("cls");
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << arr << "\n";
    // cout << &arr << "\n";
    // cout << &arr[0] << "\n";
    // cout << arr[0] << "\n";
    // cout << *(arr + 1);

    // arr[i] and i[arr] are the same things
    // arr[i]=*(arr+i)

    // pointers behaviour is different in case of character arrays
    // char ch[] = "Babbar";

    // char *c = ch;

    // Here address will not be printed rather the whole string will be printed
    // since the behaviour/implementation is different of cout in case of characters
    // cout << c << " ";

    // cout << ch << "\n";
    // cout << &ch << "\n";
    // cout << ch[0] << "\n";
    // cout << &c << "\n";
    // cout << *c << "\n";
    // cout << c << "\n";

    // char name[10] = "SherBano";
    // char *cptr = &name[0];

    // cout << name << "\n";
    // cout << &name << "\n";
    // cout << *(name + 3) << "\n";
    // cout << cptr << "\n";
    // cout << &cptr << "\n";
    // cout << *(cptr + 3) << "\n";
    // cout << cptr + 2 << "\n";
    // cout << *cptr << "\n";
    // cout << cptr + 8 << "\n";

    // char ch = 'a';
    // char *cptr = &ch;
    // cout << cptr << "\n";
    // This will be printed till a null character will be found, which will be garbage value

    // What happens is that 'babbar' is stored quickly in a temporary memory and then after
    // that the memory location changes and the array points to it. But here in this case
    // the string is just stored in the temporary location. It is unpredictable, can change
    // anytime.

    // char *c = "babbar";
    // cout << c << "\n";

    // The size of the array inside the main function will be different and inside other
    // function will be different since the arrays are passed by reference not pass by value
    // so here only the reference of the array is passed and not the original array

    int arr[] = {1, 2, 3, 4, 5};
    cout << "Size of the array is : " << sizeof(arr);
    solve(arr);

    return 0;
}