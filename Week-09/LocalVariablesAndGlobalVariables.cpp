#include <iostream>
#include <string>
using namespace std;
int x = 2; // global variable

void fun()
{
    int x = 60;
    ::x = 40;
    cout << x << " " << ::x;
}
int main()
{
    system("cls");
    // ::x = 4;    // global x
    x = 4;      // global x
    int x = 20; // local to main()
    cout << x << " ";
    cout << ::x << " ";

    //  The most local variable is given the most preference
    {
        int x = 50;
        {
            int x = 44;
            cout << x << " ";
        }
        cout << x << " " << ::x << " ";
    }
    fun();
    return 0;
}