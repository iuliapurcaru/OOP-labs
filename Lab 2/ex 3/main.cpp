#include <iostream>
#include <cstring>

using namespace std;

class Sibling
{
public:
    char *surname;
    char *name;
    char *age;
    Sibling(const char *snm, const char *nm, const char *ag);
    ~Sibling();
    Sibling(const Sibling&, const Sibling&);
    void update(const char*, const char*);
};

Sibling::Sibling(const char *snm, const char *nm, const char *ag)
{
    surname = new char[10];
    strcpy(surname, snm);
    name = new char[10];
    strcpy(name, nm);
    age = new char[3];
    strcpy(age, ag);
}

Sibling::~Sibling(void)
{
    cout << "--Object is being deleted--" << endl;
}

void Sibling::update(const char *new_name, const char *new_age)
{
    name = new char[10];
    strcpy(name, new_name);

    age = new char[3];
    strcpy(age, new_age);
}

Sibling::Sibling(const Sibling &new_name, const Sibling &new_age){
    name = new char[10];
    strcpy(name, new_name.name);

    age = new char[3];
    strcpy(age, new_age.age);
}

int main()
{
    Sibling sibling1("Popescu", "Andrei", "20");
    Sibling sibling2 = sibling1;

    sibling2.update("Alexandru", "18");

    cout << sibling1.surname << " " << sibling1.name << ", " << sibling1.age << endl;
    cout << sibling2.surname << " " << sibling2.name << ", " << sibling2.age << endl;
    cout << endl;

    return 0;
}
