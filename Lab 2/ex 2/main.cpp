#include <iostream>

using namespace std;

class Car{
public:
    string brand;
    string model;
    int production_year;
    string fuel;
    Car();
    Car(string br, string md, int pd, string fl);
    Car(string md, int pd, string fl);
    Car(string md, int pd);
    ~Car();
};

Car::Car(){
    brand = "Hyundai";
    model = "i10";
    production_year = 2020;
    fuel = "benzina";
}

Car::Car(string br, string md, int pd, string fl){
    brand = br;
    model = md;
    production_year = pd;
    fuel = fl;
}

Car::Car(string md, int pd, string fl){
    brand = "Hyundai";
    model = md;
    production_year = pd;
    fuel = fl;
}

Car::Car(string md, int pd){
    brand = "Hyundai";
    model = md;
    production_year = pd;
    fuel = "diesel";
}

Car::~Car(void){
    cout << "Object is being deleted" << endl;
}

int main()
{
    Car car_1;
    Car car_2("Hyundai", "i20", 2019, "benzina");
    Car car_3("i30", 2019, "diesel");
    Car car_4("i40", 2021);

    cout << car_1.brand << " " << car_1.model << " " << car_1.production_year << " " << car_1.fuel << endl;
    cout << car_2.brand << " " << car_2.model << " " << car_2.production_year << " " << car_2.fuel << endl;
    cout << car_3.brand << " " << car_3.model << " " << car_3.production_year << " " << car_3.fuel << endl;
    cout << car_4.brand << " " << car_4.model << " " << car_4.production_year << " " << car_4.fuel << endl;
    cout << endl;

    return 0;
}
