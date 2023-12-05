#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
// Optimised sieve
vector<bool> Sieve(int n)
{
    // Create a sieve array of N size telling isPrime
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    // Optimisation 2
    // for (int i = 2; i < n; i++)
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            // first optimization, since all the previous number would have been marked
            // so start from i * i.
            // int j = i * 2;
            int j = i * i;
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}
vector<bool> segSieve(int l, int r)
{
    // get me the sieve array which will help us to mark the non primes in the segmented sieve
    vector<bool> sieve = Sieve(sqrt(r));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }
    // find first index to start marking, since we want the first multiples which are in a higher
    // range and not starting from 0, hence formula needs to be applied
    vector<bool> segsieve(r - l + 1, true);
    if (l == 0 || l == 1)
        segsieve[l] = false;

    for (int prime : basePrimes)
    {
        int firstmultiple = (l / prime) * prime;
        if (firstmultiple < l)
        {
            firstmultiple += prime;
        }
        int j = max(firstmultiple, prime * prime);
        while (j <= r)
        {
            segsieve[j - l] = false;
            j += prime;
        }
    }
    return segsieve;
}
int main()
{
    system("cls");
    // vector<bool> sieve = Sieve(25);
    // for (int i = 0; i < 25; i++)
    // {
    //     if (sieve[i])
    //     {
    //         cout << i << " ";
    //     }
    // }
    int l = 110;
    int r = 130;
    vector<bool> ans = segSieve(l, r);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i])
        {
            cout << i + l << " ";
        }
    }
    return 0;
}