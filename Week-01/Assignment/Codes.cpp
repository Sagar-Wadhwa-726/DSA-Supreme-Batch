#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

/*Program to find the factorial of a number*/

// int main()
// {
//     system("cls");
//     int n;
//     cin >> n;
//     int ans = 1;

//     for (int i = n; i >= 1; i--)
//     {
//         ans = ans * i;
//     }
//     cout << ans;
//     return 0;
// }

/*Program to check if a number is prime or not*/

// int main()
// {
//     system("cls");
//     int n;
//     bool flag = true;
//     cin >> n;
//     if (n == 0 || n == 1)
//     {
//         cout << n << " is not a prime number !";
//         return 0;
//     }
//     for (int i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << "not prime";
//             flag = false;
//             return 0;
//         }
//     }
//     if (flag)
//         cout << "prime";
//     return 0;
// }

// A valid triangle is a triangle where the sum of any two sides is greter
// than the third side
// a+b>c, b+c>a, c+a>b

/*Program to find the maximum of three numbers*/

// int main()
// {
//     system("cls");
//     int a, b, c;
//     cin >> a >> b >> c;
//     int max = a;
//     if (b > max && b > c)
//         max = b;
//     else if (c > max && c > b)
//         max = c;
//     cout << "maximum of " << a << " " << b << " " << c << " is:" << max;
//     return 0;
// }