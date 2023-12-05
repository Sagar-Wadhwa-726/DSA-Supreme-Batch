#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstdalign>
#include <cstring>
#include <string>
using namespace std;
int iterativeLeftToRight(string &s, char key)
{
    int index = -1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == key)
            index = i;
    return index;
}
int iterativeRightToLeft(string &s, char &key)
{
    int index = -1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == key)
        {
            index = i;
            break;
        }
    }
    return index;
}
void findLastOccurrenceRecursiveLeftToRight(string &s, char &key, int index, int &ans)
{
    if (index >= s.size())
        return;

    if (s[index] == key)
    {
        ans = index;
    }

    findLastOccurrenceRecursiveLeftToRight(s, key, index + 1, ans);
}
void findLastOccurrenceRecursiveRightToLeft(string &s, char &key, int index, int &ans2)
{
    if (index < 0)
        return;

    if (s[index] == key)
    {
        ans2 = index;
        return;
    }

    findLastOccurrenceRecursiveRightToLeft(s, key, index - 1, ans2);
}
int main()
{
    system("cls");
    string s = "abcdded";
    char key = 'd';
    int ans = -1;
    int ans2 = -1;

    cout << key << " last occurence is at index : " << iterativeLeftToRight(s, key);
    cout << "\n";

    cout << key << " last occurence is at index : " << iterativeRightToLeft(s, key);
    cout << "\n";

    findLastOccurrenceRecursiveLeftToRight(s, key, 0, ans);
    cout << key << " last occurence is at index : " << ans;
    cout << "\n";

    findLastOccurrenceRecursiveRightToLeft(s, key, s.size() - 1, ans2);
    cout << key << " last occurence is at index : " << ans2;
    cout << "\n";

    // strrchr in built method can also be used for this work.
    return 0;
}