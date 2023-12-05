// https://leetcode.com/problems/palindrome-number/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
bool palindromeCheckRE(string &s, int index)
{
    if (index >= s.size() / 2)
        return true;

    if (s[index] != s[s.size() - 1 - index])
        return false;

    return palindromeCheckRE(s, index + 1);
}
int main()
{
    system("cls");
    string s = "racecar";
    if (palindromeCheckRE(s, 0))
        cout << s << " is a palindrome !";
    else
        cout << s << " is not a palindrome !";
    return 0;
}