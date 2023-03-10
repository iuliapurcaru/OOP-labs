#include <iostream>
#include <string>

using namespace std;

template <typename X>
void concat(X x, X y)
{
    cout << "Main template: " << endl;
    cout << "First element: " << x << endl;
    cout << "Second element: " << y << endl;
    cout << "After concatenation: " << x + y << endl;
}

template<>
void concat(int x, int y)
{
    cout << "Int template: " << endl;
    cout << "First element: " << x << endl;
    cout << "Second element: " << y << endl;
    
    string str1 = to_string(x);
    string str2 = to_string(y);

    cout << "After concatenation: " << str1 + str2 << endl;
}

template<>
void concat(char x, char y)
{
    cout << "Char template: " << endl;
    cout << "First element: " << x << endl;
    cout << "Second element: " << y << endl;
    
    string str = string(1, x) + y;
    cout << "After concatenation: " << str << endl;
}

int main()
{
    concat<string>("Hello ", "World");
    cout << endl;
    
    concat<int>(23, 65);
    cout << endl;

    concat<char>('a', 'B');
    cout << endl;
}

