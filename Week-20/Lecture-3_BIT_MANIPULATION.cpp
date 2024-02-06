#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void checkOddOrEvenBitMasking(int n)
{
    if (n & 1)
        cout << "Number is odd";
    else
        cout << "Number is even";
}
void getIthBitOfANumber(int n, int i)
{
    // create a mask
    int mask = 1 << i;
    if ((n & mask) == 0)
        cout << "Bit is 0";
    else
        cout << "Bit is 1";
}
void setIthBit(int n, int i)
{
    int mask = 1 << i;
    int ans = (n | mask);
    cout << ans;
}
void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
    cout << "answer is : ";
    cout << n << "\n";
}
void updateIthBit(int &n, int i, int target)
{
    clearIthBit(n, i);
    int mask = target << i;
    n = n | mask;
    cout << n;
}
void clearLastBits(int n, int i)
{
    int mask = (-1 << i);
    cout << (n & mask);
}
void checkPowerOfTwoOrNot(int n)
{
    if (!((n & (n - 1))))
        cout << "Number is a power of 2";
    else
        cout << "Number is not a power of 2";
}
void countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        int lastBit = (n & 1);
        if (lastBit)
            count++;
        n = (n >> 1);
    }
    cout << "Number of set bits is : " << count;
}
void countSetBitsFast(int n)
{
    int count = 0;
    while (n != 0)
    {
        // remove last set bit
        n = (n & (n - 1));
        count++;
    }
    cout << "Number of set bits is : " << count;
}
void clearBitsInRange(int n, int i, int j)
{
    int a = (-1 << (i + 1));
    int b = (1 << j) - 1;
    int mask = a | b;
    int ans = n & mask;
    cout << ans;
}
void getSubsequencesUsingBitMasking(string str)
{
    vector<string> ans;
    int n = str.length();
    for (int num = 0; num < (1 << n); num++)
    {
        // to store a answer, we will create subsequence string in this temp string
        string temp;

        // loop to exclude/include a character
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
                temp.push_back(str[i]);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    cout << "Printing the subsequences of " << str << " : ";
    cout << "\n";
    for (string s : ans)
        cout << s << "\n";
}
int main()
{
    system("cls");

    // CHECK WHETHER A NUMBER IS ODD OR EVEN USING BIT MASKING
    checkOddOrEvenBitMasking(5);
    cout << "\n";

    // GET THE ITH BIT OF A NUMBER (0-INDEXED)
    getIthBitOfANumber(10, 3);
    cout << "\n";

    // SET ITH BIT
    setIthBit(10, 2);
    cout << "\n";

    // CLEAR ITH BIT
    int num = 10;
    clearIthBit(num, 1);
    cout << "\n";

    // UPDATE ITH BIT
    int n = 10;
    updateIthBit(n, 0, 1);
    cout << "\n";

    // CLEAR LAST BITS
    clearLastBits(7, 2);
    cout << "\n";

    // CHECK IF A NUMBER IS A POWER OF 2 OR NOT
    checkPowerOfTwoOrNot(4);
    cout << "\n";

    // COUNT THE NUMBER OF SET BITS
    countSetBits(15);
    cout << "\n";

    // COUNT THE NUMBER OF SET BITS - FAST WAY
    countSetBitsFast(15);
    cout << "\n";

    // CLEAR BITS IN A RANGE
    clearBitsInRange(15, 2, 1);
    cout << "\n";

    // FIND SUBSEQUENCES USING BIT MASKING
    getSubsequencesUsingBitMasking("abc");
    return 0;
}