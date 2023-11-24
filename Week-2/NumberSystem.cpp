#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

/*Program to convert decimal to binary and vice-versa*/

int decimalToBinaryMethodTwo(int n)
{
    // Another method to convert the decimal number into binary number can be by finding the
    // least Significant bit, which can be done by anding the number with 1, and then repeatedly
    // right shifting the number
    int binaryNumber = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = (n & 1);
        binaryNumber = bit * pow(10, i++) + binaryNumber;
        n = n >> 1;
    }
    return binaryNumber;
}
int decimalToBinary(int n)
{
    int ans = 0;
    int i = 0;
    // Keep on dividing by 2 till the number becomes 0
    while (n > 0)
    {
        int bit = n % 2;
        ans = ans + bit * pow(10, i);
        i++;
        n = n / 2;
    }
    return ans;
}
int binaryToDecimal(int n)
{
    int i = 0;
    int decimal = 0;
    while (n)
    {
        int bit = n % 10;
        decimal = decimal + bit * pow(2, i++);
        n = n / 10;
    }
    return decimal;
}
int main()
{
    system("cls");
    int n;
    cin >> n;
    int binary = decimalToBinaryMethodTwo(n);
    cout << binary;
    cout << "\n";
    cout << "Enter a number again:";
    cin >> n;
    int decimal = binaryToDecimal(n);
    cout << decimal;
    return 0;
}