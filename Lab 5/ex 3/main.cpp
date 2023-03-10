#include <iostream>

using namespace std;

class Concatenation
{
private:
    string string1, string2;

public:
    Concatenation(string s1, string s2)
    {
        string1 = s1;
        string2 = s2;
    }

    void operator +()
    {
        string str = string1 + string2;
        cout << "Final string: " << str << endl;
    }

    void print()
    {
        cout << "String 1: " << string1 << endl;
        cout << "String 2: " << string2 << endl;
    }
};

int main()
{
    Concatenation concat("test ", "string");
    concat.print();
    +concat;

    return 0;
}
