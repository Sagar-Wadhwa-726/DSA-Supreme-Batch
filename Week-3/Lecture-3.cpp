// Slides not available
// 2-D arrays
// compulsary to pass the number of columns in the function of an array, no need to provide the row number
// but providing the column number is always necessary
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <limits>
using namespace std;

/*Row sum print of a 2d matrix*/

// int main()
// {
//     system("cls");
//     // Creation of a 2d vector/array
//     int arr[5][4] = {
//         {1, 2, 3, 4},
//         {2, 3, 4, 1},
//         {5, 6, 1, 3},
//         {2, 4, 6, 8},
//         {1, 9, 9, 6},
//     };
//     int rowSum = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             rowSum = rowSum + arr[i][j];
//         }
//         cout << "The sum of the elements in the row number " << i << " is : " << rowSum << "\n";
//         rowSum = 0;
//     }
//     return 0;
// }

/*Column sum of a matrix*/

// int main()
// {
//     system("cls");
//     // Creation of a 2d vector/array
//     int arr[5][4] = {
//         {1, 2, 3, 4},
//         {2, 3, 4, 1},
//         {5, 6, 1, 3},
//         {2, 4, 6, 8},
//         {1, 9, 9, 6},
//     };
//     int colSum = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             colSum = colSum + arr[j][i];
//         }
//         cout << "The sum of the elements in the column number " << i << " is : " << colSum << "\n";
//         colSum = 0;
//     }
//     return 0;
// }

/*Transpose of a matrix*/

// int main()
// {
//     system("cls");
//     int arr[3][3] = {
//         {2, 4, 6},
//         {1, 3, 5},
//         {5, 11, 13},
//     };
//     // Doing the transpose of the matrix
//     // The columns should be made as the row and the row should be made as the column
//     int brr[3][3];
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             // This will do double swap, so transpose can't be done in the same array
//             // We have to use another array
//             // int temp = arr[i][j];
//             // arr[i][j] = arr[j][i];
//             // arr[j][i] = temp;

//             brr[j][i] = arr[i][j];
//         }
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout << brr[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

/*Using vector of vector*/

int main()
{
    system("cls");
    vector<vector<int>> arr(3, vector<int>(3));
    return 0;
}

/*Homework questions

1. Rotate the matrix by 90 degree
2. Spiral print a matrix
3. Wave print a matrix
4. Median of a 2D array
5. Sort 0's, 1's, 2's
6. Move all -ve's to one side of the array
7. Find duplicate element
8. Find missing element
9. Find first repeating element
10. Find common elements in the 3 arrays
11. Factorial of a large number

*/
