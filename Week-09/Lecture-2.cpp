/*Inheritance should be used for the reusability of code and to avoid typing or copy pasting the same code
again and again.*/
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

/*Single level inheritance*/
class Animal
{
public:
    int age;
    int weight;

    void eat()
    {
        cout << "Animal is eating !";
    }

    void speak()
    {
        cout << "Animal is barking !";
    }
};
class Dog : public Animal
{
public:
    bool isMale;

    void free()
    {
        cout << "I am freed yayyyyyyyy !";
    }
};

/*Multi level inheritance*/
class Fruit
{
public:
    string name;
};
class Mango : public Fruit
{
public:
    int weight;
};
class Alphanso : public Mango
{
public:
    int sugarLevel;
};

/*Multiple inheritance*/
class A
{
public:
    int physics;
    int ambiguityVariable = 99;
};
class B
{
public:
    int chemistry;
    int ambiguityVariable = 98;
};
class C : public A, public B
{
public:
    int maths;
};

/*Hierarichal Inhertance*/
class Car
{
public:
    int age;
    int weight;
    string name;

    void speedUp()
    {
        cout << "Speeding Up" << endl;
    }
};

class Scorpio : public Car
{
};
class Fortuner : public Car
{
};

/*Hybrid inheritance --> Mixture of multiple inhertances*/

/*Function overloading (COMPILE TIME POLYMORPHISM)*/
class Maths
{
public:
    int maths(int a, int b)
    {
        return a + b;
    }
    int maths(int a, int b, int c)
    {
        return a + b + c;
    }
};

/*Operator overloading (COMPILE TIME POLYMORPHISM)*/
class ImaginaryNumber
{
private:
    float real;
    float imaginary;

public:
    ImaginaryNumber operator+(ImaginaryNumber &obj2)
    {
        float real1 = this->real;
        float real2 = obj2.real;
        float imag1 = this->imaginary;
        float imag2 = obj2.imaginary;

        float realSum = real1 + real2;
        float imagSum = imag1 + imag2;

        ImaginaryNumber temp;
        temp.real = realSum;
        temp.imaginary = imagSum;
        return temp;
    }

    void setReal(float real)
    {
        this->real = real;
    }
    void setImag(float imaginary)
    {
        this->imaginary = imaginary;
    }
    float getReal()
    {
        return this->real;
    }
    float getImag()
    {
        return this->imaginary;
    }
};
int main()
{
    system("cls");
    // Dog d1;
    // d1.eat();
    // cout << "\n";
    // d1.speak();
    // cout << "\n";
    // d1.isMale = false;
    // if (d1.isMale)
    //     cout << "This is a male animal !";
    // else
    //     cout << "This is a female animal !";
    // cout << "\n";

    // Alphanso a;
    // a.name = "Alphanso";
    // a.weight = 1;
    // a.sugarLevel = 1453244123;
    // cout << a.name << " " << a.weight << " " << a.sugarLevel << "\n";

    // C obj;
    // obj.physics = 90;
    // obj.chemistry = 80;
    // obj.maths = 70;
    // cout << obj.physics << " " << obj.chemistry << " " << obj.maths << "\n";
    // cout << obj.A::ambiguityVariable << " " << obj.B::ambiguityVariable << "\n";

    // Scorpio s11;
    // s11.speedUp();
    // Fortuner f11;
    // f11.speedUp();

    // Maths obj;
    // cout << obj.maths(1, 2) << " " << obj.maths(4, 5, 6);

    ImaginaryNumber a;
    a.setReal(5.6);
    a.setImag(5.1);
    ImaginaryNumber b;
    b.setReal(9.1);
    b.setImag(4.8);

    ImaginaryNumber c = a + b;
    cout << c.getReal() << "+" << c.getImag() << "i";
    return 0;
}