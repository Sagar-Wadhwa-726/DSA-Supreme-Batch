#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Box
{
private:
    int width;
    Box(int _w) : width(_w){};
    const void setWidth(int width)
    {
        this->width = width;
    }

public:
    const int getWidth()
    {
        return this->width;
    }

    // The BoxFactory class can access the private members of Box class
    friend class BoxFactory;
};
class BoxFactory
{
private:
    int count;

public:
    Box getABoxObject(int _w)
    {
        // This class is a friend of Box class and hence can access the 'private' ctor
        // Count can also be used to keep a track of the number of objects which are created.
        ++count;
        return Box(_w);
    }
};
int main()
{
    system("cls");
    // Box *box = new Box(5); --> private ctor, can't be used to initialise anything. Hence it can't be called, these are used when we want the object of the class not to be created directly but when we want the object of the class to be created by some other factory class.

    // cout << box->getWidth() << "\n";

    BoxFactory bfact;
    Box b = bfact.getABoxObject(5);

    cout << b.getWidth() << "\n";

    // https://learn.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=msvc-170

    return 0;
}