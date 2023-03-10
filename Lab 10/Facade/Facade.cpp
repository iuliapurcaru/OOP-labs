#include <iostream>

using namespace std;

class Subsystem1 
{
public:

    void Operation()
    {
        cout << "You are now in Subsystem 1!" << endl;
    }
};

class Subsystem2 
{
public:

    void Operation()
    {
        cout << "You are now in Subsystem 2!" << endl;
    }
};

class Facade 
{
private:

    Subsystem1 one;
    Subsystem2 two;
    
public:

    void Operation1() 
    {
        cout << "Facade operation 1: ";
        one.Operation();
    }

    void Operation2()
    {
        cout << "Facade operation 2: ";
        two.Operation();
    }
};

int main() 
{
    Facade* facade = new Facade;
    
    facade->Operation1();
    cout << endl;
    facade->Operation2();

    delete facade;

    return 0;
}

/*
Avantaje:
- codul este mai usor de inteles si editat deoarece metodele sunt bine organizate in subsisteme
- ascunde complexitatea codului de utilizator

Dezavantaje:
- poate afecta eficienta programului deoarece este o abordare indirecta
*/
