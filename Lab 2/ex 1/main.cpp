#include <iostream>
#include <ctime>

using namespace std;

class curent_time {
public:
    curent_time() {
    time_t now = time(0);
    cout << ctime(&now) << endl;
    }
    ~curent_time(){
    cout << "Object is being deleted" << endl;
    };
};

int main() {

   curent_time time_now;
   return 0;

}
