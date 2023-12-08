// CLIENT USES THE HEADER FILE PROVIDED BY THE VENDOR (VENDOR-CLIENT MODEL)
#include "bird.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
}
int main()
{
    system("cls");
    Bird *bird = new Sparrow;
    birdDoesSomething(bird);
    return 0;
}