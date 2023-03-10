#include<iostream>
#include <cstring>
using namespace std;

class Sibling
{
    private:
        char *nume;
        char *prenume;
        char *varsta;
        int size;
    public:
        Sibling(const char *n, const char *pr, const char *v);
        ~Sibling();
        Sibling(const Sibling& initialName, const Sibling& initialPrenume, const Sibling& initialVarsta);
        void print()
        {
            cout << nume <<" " << prenume <<" "<< varsta << endl;
        }
        void update(const char *, const char *, const char *);

};

Sibling::Sibling(const char *n, const char *pr, const char *v)
{
    size = strlen(n);
    nume = new char[size+1];
    strcpy(nume, n);

    size = strlen(pr);
    prenume = new char[size+1];
    strcpy(prenume, pr);

    size = strlen(v);
    varsta = new char[size+1];
    strcpy(varsta, v);
}
void Sibling::update(const char *n, const char *pr, const char *v)
{
    delete [] prenume;
    delete [] varsta;
    size = strlen(nume);
    nume = new char[size+1];
    strcpy(nume, n);

    size = strlen(prenume);
    prenume = new char[size+1];
    strcpy(prenume, pr);

    size = strlen(varsta);
    varsta = new char[size+1];
    strcpy(varsta, v);
}

Sibling::Sibling(const Sibling& initialName, const Sibling& initialPrenume, const Sibling& initialVarsta)
{
    size = initialName.size;
    nume = new char[size + 1];
    strcpy(nume, initialName.nume);
}

Sibling::~Sibling()
{
    delete [] nume;
    delete [] prenume;
    delete [] varsta;
}


int main()
{
    Sibling sibling1("Radoi", "Ionut", "20");
    Sibling sibling2 = sibling1;

    sibling1.print();
    sibling2.print();

    sibling2.update("Radoi", "Nicolae", "18");

    sibling1.print();
    sibling2.print();

    return 0;

}
