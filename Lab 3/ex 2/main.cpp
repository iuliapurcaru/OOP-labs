#include <iostream>
#include <cmath>

using namespace std;

class Student
{
private:
    string nume;
    string prenume;
    string CNP;
    int anul_nasterii;
    string facultate;
    int anul_infiintarii;

public:

    // setters

    void setNume(string Nume)
    {
        this->nume = Nume;
    }

    void setPrenume(string Prenume)
    {
        this->prenume = Prenume;
    }

    void setCNP(string CNP)
    {
        this->CNP = CNP;
    }

    void setAnulNasterii(int anul_nasterii)
    {
        this->anul_nasterii = anul_nasterii;
    }

    void setFacultate(string Facultate)
    {
        this->facultate = Facultate;
    }

    void setAnulInfiintarii(int anul_infiintarii)
    {
        this->anul_infiintarii = anul_infiintarii;
    }

    // getters

    string getNume()
    {
        return this->nume;
    }

    string getPrenume()
    {
        return this->prenume;
    }

    string getCNP()
    {
        return this->CNP;
    }

    int getAnulNasterii()
    {
        return this->anul_nasterii;
    }

    string getFacultate()
    {
        return this->facultate;
    }

    int getAnulInfiintarii()
    {
        return this->anul_infiintarii;
    }

    //

    void deteminare_sex()
    {
        if(CNP[0] == '1' || CNP[0] == '5' || CNP[0] == '7')
            cout << "Sex: masculin" << endl;
        else cout << "Sex: feminin" << endl;
    }

    void determinare_varsta()
    {
        cout << "Varsta: " << 2021 - anul_nasterii << endl;
    }

    void determinare_diferenta()
    {
        cout << "Diferenta de ani: " << abs(anul_infiintarii - anul_nasterii) << endl;
    }

    ~Student()
    {
        delete &nume;
        delete &prenume;
        delete &CNP;
        delete &anul_nasterii;
        delete &facultate;
        delete &anul_infiintarii;
    }
};

int main()
{
    Student student1;
    Student student2;


    // exemplu 1

    student1.setNume("Popescu");
    student1.setPrenume("Ana");
    student1.setCNP("6011203447083");
    student1.setAnulNasterii(2001);
    student1.setFacultate("Facultatea de Automatica si Calculatoare");
    student1.setAnulInfiintarii(1963);

    cout << "Student 1:" << endl;
    cout << "Nume: " << student1.getNume() << endl;
    cout << "Prenume; " << student1.getPrenume() << endl;
    cout << "CNP: " << student1.getCNP() << endl;
    cout << "Anul nasterii: " << student1.getAnulNasterii() << endl;
    cout << "Facultate: " << student1.getFacultate() << endl;
    cout << "Anul infiintarii facultatii: " << student1.getAnulInfiintarii() << endl;

    student1.deteminare_sex();
    student1.determinare_varsta();
    student1.determinare_diferenta();

    cout << endl;

    // exemplu 2

    student2.setNume("Radulescu");
    student2.setPrenume("Andrei");
    student2.setCNP("1980513328616");
    student2.setAnulNasterii(1998);
    student2.setFacultate("Facultatea de Drept");
    student2.setAnulInfiintarii(1859);

    cout << "Student 2:" << endl;
    cout << "Nume: " << student2.getNume() << endl;
    cout << "Prenume; " << student2.getPrenume() << endl;
    cout << "CNP: " << student2.getCNP() << endl;
    cout << "Anul nasterii: " << student2.getAnulNasterii() << endl;
    cout << "Facultate: " << student2.getFacultate() << endl;
    cout << "Anul infiintarii facultatii: " << student2.getAnulInfiintarii() << endl;

    student2.deteminare_sex();
    student2.determinare_varsta();
    student2.determinare_diferenta();

    return 0;
}
