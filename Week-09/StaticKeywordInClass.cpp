// #include <stdio.h>
// #include <stdlib.h>
// #include <iostream>
// #include <conio.h>
// #include <vector>
// #include <math.h>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <limits>
// #include <stack>
// using namespace std;
// class abc
// {
// public:
//     int x, y;

//     void print()
//     {
//         cout << this->x << " " << this->y << "\n";
//     }
// };
// int main()
// {
//     system("cls");
//     abc obj1 = {1, 2}, obj2 = {4, 5};
//     obj1.print();
//     obj2.print();
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <iostream>
// #include <conio.h>
// #include <vector>
// #include <math.h>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <limits>
// #include <stack>
// using namespace std;
// class abc
// {
// public:
//     static int x, y;

//     void print()
//     {
//         cout << x << " " << y << "\n";
//     }
// };

// /*This is the initialisation of the static data members outside the class, this is mandatory*/
// int abc::x;
// int abc::y;
// int main()
// {
//     system("cls");
//     abc obj1, obj2;
//     obj1.x = 1;
//     obj1.y = 2;
//     obj1.print();
//     obj2.x = 10;
//     obj2.y = 20;
//     obj1.print();
//     obj2.print();
//     return 0;
// }

// // Static data members can be called via the class name or object name both
// // They are set to a default value of 0
// // Initialisation of the static data members outside the class is mandatory

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits>
#include <stack>
using namespace std;
class abc
{
public:
    int x, y;

    abc() : x(0), y(0) {}

    static void print()
    {
        // cout << x << " " << y << "\n";

        printf("I am in function whose name is : %s", __FUNCTION__);
    }
};
int main()
{
    system("cls");
    abc obj1, obj2;
    abc::print();
    return 0;
}