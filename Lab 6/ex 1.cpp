#include <iostream>

using namespace std;

class Country
{
public:
    virtual void capital() = 0;
    virtual void population() = 0;
    virtual void area() = 0;

    void print()
    {
        capital();
        population();
        area();
    }
};

class Austria : public Country
{
public:
    void capital()
    {
        cout << "Capital: Vienna" << endl;
    }

    void population()
    {
        cout << "Population: 8,935,112" << endl;
    }

    void area()
    {
        cout << "Area: 83,879 km2" << endl;
    }
};

class Canada : public Country
{
public:
    void capital()
    {
        cout << "Capital: Ottawa" << endl;
    }

    void population()
    {
        cout << "Population: 38,246,108" << endl;
    }

    void area()
    {
        cout << "Area: 9,984,670 km2" << endl;
    }
};

class Japan : public Country
{
public:
    void capital()
    {
        cout << "Capital: Tokyo" << endl;
    }

    void population()
    {
        cout << "Population: 125,360,000" << endl;
    }

    void area()
    {
        cout << "Area: 377,975 km2" << endl;
    }
};

int main()
{
    Austria austria;
    Canada canada;
    Japan japan;

    cout << "---Austria---" << endl;
    austria.print();
    cout << endl;

    cout << "---Canada---" << endl;
    canada.print();
    cout << endl;

    cout << "---Japan---" << endl;
    japan.print();
    cout << endl;

    return 0;
}
