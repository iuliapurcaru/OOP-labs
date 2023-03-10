#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;
    string gender;

public:
    void SetData(string n, int a, string gen)
    {
        name = n;
        age = a;
        gender = gen;
    }

    void PrintData()
    {
        cout << "--Personal details--" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

};

class Employee : public Person
{
private:
    float salary;
    string department;

public:
    void SetData(float sal, string dep)
    {
        salary = sal;
        department = dep;
    }

    void PrintData()
    {
        cout << "--Employee details--" << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }

};

class Department : public Employee
{
private:
    string position;
    int id_number;

public:
    void SetData(string pos, int id)
    {
        position = pos;
        id_number = id;
    }

    void PrintData()
    {
        cout << "--Department details--" << endl;
        cout << "Position: " << position << endl;
        cout << "ID number: " << id_number << endl;
    }

};

int main()
{
    Department employee;

    employee.SetData("Computer programmer", 1234);
    employee.Employee::SetData(2345.67, "IT");
    employee.Person::SetData("Popescu Andrei", 26, "M");

    employee.Person::PrintData();
    employee.Employee::PrintData();
    employee.PrintData();

    return 0;
}
