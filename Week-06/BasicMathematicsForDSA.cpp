// Count primes question on leetcode
// https://leetcode.com/problems/count-primes/

// gcd(a,b) = gcd(a-b,b) if a>b
// gcd(a,b) = gcd(b-a,b) if a>b
// repeat this till any one a or b becomes 0, if one 0 other parameter is the answer

// gcd(a,b) = gcd(a%b,b) --> but divide operation is heavy so ignore it

// https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// LCM * HCF = A * B

// https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <malloc.h>
#include <math.h>
#include <ios>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <conio.h>
using namespace std;
int slowExponentiation(int a, int b)
{
    // T.C => O(b)
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}
int fastExponentiation(int a, int b)
{
    // T.C => O(log(b))
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1;
    }
    return ans;
}
int main()
{
    system("cls");
    cout << "Answer from slow exponentation is : " << slowExponentiation(2, 5);
    cout << "\n";
    cout << "Answer from fast exponentation is : " << fastExponentiation(2, 5);
    return 0;
}