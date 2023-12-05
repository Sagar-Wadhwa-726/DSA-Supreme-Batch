#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/*Printing digits of a number*/

// int main()
// {
//     system("cls");
//     int n = 623;
//     while (n != 0)
//     {
//         int rem = n % 10;
//         n = n / 10;
//         cout << rem;
//     }
//     return 0;
// }

/*Creating a number from the given digits*/

// int main()
// {
//     system("cls");
//     int ans = 0;
//     int digits[] = {8, 2, 3, 7};
//     for (int i = 0; i < 4; i++)
//     {
//         ans = ans * 10 + digits[i];
//     }
//     cout << ans;
//     return 0;
// }

/*Program to count the number of set bits*/

// This code will break for negative numbers, because of the padding concept
// int main()
// {
//     int n = 11;
//     int x = n;
//     int ans = 0;
//     while (n != 0)
//     {
//         if (n & 1 == 1)
//             ans++;
//         n = n >> 1;
//     }
//     cout << "Number of set bits in " << x << " is: " << ans;
// }