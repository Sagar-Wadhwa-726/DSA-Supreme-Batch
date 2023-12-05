/*Array class-1
Learning about the basics of arrays - initialsing the array, taking input in the
array, printing the output etc. */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <limits>
#include <math.h>
using namespace std;

/*Basic operations of array*/

// int main()
// {
//     system("cls");
//     int arr[] = {2, 4, 6, 8, 10};
//     for (int i = 0; i < 5; i++)
//     {
//         arr[i] = 1;
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

/*Memset function in C++*/

// int main()
// {
//     system("cls");
//     // Arrays are always passed by reference
//     int arr[10];
//     memset(arr, 21, (size_t)arr + 10);
//     for (int i = 0; i < 10; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

/*Arrays and functions*/

// Arrays are always passed by reference
// void inc(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//         arr[i] = 2 * arr[i];
// }
// void printarray(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//         cout << arr[i] << " ";
// }
// int main()
// {
//     int arr[] = {5, 6};
//     int size = 2;
//     inc(arr, size);
//     printarray(arr, size);
// }

/*Linear search in array*/

// void linearSearch(int arr[], int size, int key)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == key)
//         {
//             cout << "Found " << key << " at index: " << i;
//             return;
//         }
//     }
//     cout << key << " is not present in the array!";
//     return;
// }
// int main()
// {
//     system("cls");
//     int arr[] = {4, 5, 1, 2, 8, 9, 11, 0, 15, 3};
//     int size = 10;
//     linearSearch(arr, 10, 3);
//     return 0;
// }

/*Extreme print in the array*/

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int left = 0;
//     int right = 8;
//     while (left <= right)
//     {
//         if (left == right)
//         {
//             cout << arr[left];
//             break;
//         }
//         cout << arr[left] << " & " << arr[right] << "\n";
//         left++;
//         right--;
//     }
// }

/*Reverse the array*/

// int main()
// {
//     system("cls");
//     int arr[] = {10, 20, 30, 40, 50};
//     int size = 5;
//     cout << "The original array is : ";
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     for (int i = 0; i < size / 2; i++)
//     {
//         int temp = arr[i];
//         arr[i] = arr[size - i - 1];
//         arr[size - i - 1] = temp;
//     }

//     cout << "\nThe reversed array is : ";

//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

/*Swapping can be done using the in built function, or we can make use of a temporary variable, or
we can avoid the use of the temporary variable by using +,- or we can swap two numbers by using
XOR Operation*/

// Slides not available for this lecture