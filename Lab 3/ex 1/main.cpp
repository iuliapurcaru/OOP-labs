#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Money{
public:
    int amount;
    static int counter;

    Money();
    ~Money();

    static int Count(){
        return counter;
    }
};

Money::Money(){
    amount = rand() % 100;
    if(amount > 50)
        counter++;
}

Money::~Money(void){
    delete &amount;
}

int Money::counter = 0;

int main()
{
    srand(time(0));
    Money obj1, obj2, obj3, obj4, obj5;

    cout << "Random numbers: " << obj1.amount << " " << obj2.amount << " " << obj3.amount << " " << obj4.amount << " " << obj5.amount << endl;
    cout << "Counter = " << Money::Count();
    return 0;
}
