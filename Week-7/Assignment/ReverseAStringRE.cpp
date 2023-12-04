#include <iostream>
#include <string>
using namespace std;
void reverseStringIteratively(string &s)
{
    int index = 0;

    while (index < s.size() / 2)
    {
        char ch = s[index];
        s[index] = s[s.size() - 1 - index];
        s[s.size() - 1 - index] = ch;
        index++;
    }
}
void reverseStringRecursively(string &s, int index)
{
    // base case
    if (index >= s.size() / 2)
        return;

    // processing -> swap
    swap(s[index], s[s.size() - 1 - index]);

    reverseStringRecursively(s, index + 1);
}
int main()
{
    system("cls");
    string s = "Sagar Wadhwa";

    cout << "The original string is : " << s;
    cout << "\n";

    reverseStringIteratively(s);

    cout << "The reversed string is : " << s;
    cout << "\n";

    cout << "The original string is : " << s;
    cout << "\n";

    reverseStringRecursively(s, 0);

    cout << "The reversed string is : " << s;
    cout << "\n";

    return 0;
}