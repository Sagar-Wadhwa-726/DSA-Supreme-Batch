#include <iostream>
using namespace std;

#define PI 3.14159465             // macro, convention -> capital letters
#define MAX(x, y) (x > y ? x : y) // macro, can be used anywhere, readability increases, reusability of the code increases, we don't have to write our code again and again
float circleArea(float r)
{
    // 3.14159465 can be made as a macro (PI) and can be used anywhere in the program
    // return 3.14159465 * r * r;
    return PI * r * r;
}
float perimenterOfCircle(float r)
{
    return 2 * PI * r;
}
int main()
{
    system("cls");
    cout << "Area of the circle is : " << circleArea(65.4) << "\n";
    cout << "Perimeter of the circle is : " << perimenterOfCircle(65.4) << "\n";
    int a = 5;
    int b = 7;
    int c = MAX(a, b);
    cout << c << "\n";
    return 0;
}