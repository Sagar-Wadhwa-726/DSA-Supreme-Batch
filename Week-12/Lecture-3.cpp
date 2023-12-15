#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
string firstNonRepeatingCharacterInAStream(string &str)
{
    string ans = "";

    // Frequency array
    int freq[26] = {0};

    queue<char> q;

    for (char ch : str)
    {
        // Increment frequency for this character
        freq[ch - 'a']++;

        // push in the queue
        q.push(ch);

        // find out the previous answer
        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                ans += q.front();
                break;
            }
        }
        if (q.empty())
            ans += "#";
    }
    return ans;
}
int main()
{
    system("cls");
    string str = "zarcaazrd";

    // Q1
    cout << firstNonRepeatingCharacterInAStream(str);

    // Q2 - gas station
    // https://leetcode.com/problems/gas-station/description/

    // Q3 - sliding window maximum
    // https: // leetcode.com/problems/sliding-window-maximum/description/

    return 0;
}