#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <limits>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
    system("cls");
    int arr[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    // wave printing a matrix
    for (int colNumber = 0; colNumber < 4; colNumber++)
    {
        // if the column number is even
        if ((colNumber & 1) == 0)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << arr[j][colNumber] << " ";
            }
        }
        // if the column number is odd
        else
        {
            for (int j = 2; j >= 0; j--)
            {
                cout << arr[j][colNumber] << " ";
            }
        }
    }
    return 0;
}