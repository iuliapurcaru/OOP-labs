#include <iostream>

using namespace std;

class Wine
{
protected:
    string type;
    string origin;

public:
    Wine()
    {
        type = "Red Wine";
        origin = "Romania";
    }

    Wine(string tp, string og)
    {
        type = tp;
        origin = og;
    }

    string getType()
    {
        return type;
    }

    string getOrigin()
    {
        return origin;
    }

    ~Wine()
    {
        delete &type;
        delete &origin;
    }

};

class TypeA: private Wine
{
private:
    int length;

public:

    TypeA()
    {
        length = 3;
    }

    TypeA(int L, string tp, string og):Wine(tp, og)
    {
        length = L;
        type = tp;
        origin = og;
    }

    void area()
    {
        int area = length*length;
        cout << "Type: " << type << endl;
        cout << "Origin: " << origin << endl;
        cout << "Area: " << area << endl;
        cout << endl;
    }

    ~TypeA()
    {
        delete &length;
    }

};

class TypeB: private Wine
{
private:
    int radius;

public:
    TypeB()
    {
        radius = 3;
    }

    TypeB(int R, string tp, string og):Wine(tp, og)
    {
        radius = R;
        type = tp;
        origin = og;
    }

    void area()
    {
        float area = radius*radius*3.14;
        cout << "Type: " << type << endl;
        cout << "Origin: " << origin << endl;
        cout << "Area: " << area << endl;
        cout << endl;
    }

    ~TypeB()
    {
        delete &radius;
    }

};

class TypeC: private Wine
{
private:
    int base;
    int height;

public:
    TypeC()
    {
        base = 3;
        height = 4;
    }

    TypeC(int B, int H, string tp, string og):Wine(tp, og)
    {
        base = B;
        height = H;
        type = tp;
        origin = og;
    }

    void area()
    {
        float area = (base*height)/(float)2;
        cout << "Type: " << type << endl;
        cout << "Origin: " << origin << endl;
        cout << "Area: " << area << endl;
        cout << endl;
    }

    ~TypeC()
    {
        delete &base;
        delete &height;
    }

};

int main()
{
    //Type A

    TypeA wine1;
    TypeA wine2(4, "Rose Wine", "France");

    cout << "---Type A wines---" << endl;
    wine1.area();
    wine2.area();
    cout << "---------------" << endl << endl;

    //Type B

    TypeB wine3;
    TypeB wine4(9, "Sparkling Wine", "Australia");

    cout << "---Type B wines---" << endl;
    wine3.area();
    wine4.area();
    cout << "---------------" << endl << endl;

    //Type C

    TypeC wine5;
    TypeC wine6(7, 5, "White Wine", "Italy");

    cout << "---Type C wines---" << endl;
    wine5.area();
    wine6.area();
    cout << "---------------" << endl << endl;

    return 0;
}
