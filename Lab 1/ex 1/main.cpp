#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string nume, prenume, grupa;
    string ce_mi_a_placut_la_laboratorul_de_SDA_si_vreau_sa_fie_pastrat;
    string ce_nu_mi_a_placut_la_laboratorul_de_SDA_sau_ce_poate_fi_imbunatatit;
    string ce_imi_doresc_sa_fac_dupa_ce_termin_facultatea;
};

int main()
{
    Student student;

    student.nume = "Purcaru";
    student.prenume = "Iulia";
    student.grupa = "323AC";
    student.ce_mi_a_placut_la_laboratorul_de_SDA_si_vreau_sa_fie_pastrat = "Mi-a placut modul in care erau prezentate laboratoarele deoarece \nne vorbeati si despre utilitatea lucrurilor prezentate in viata reala.";
    student.ce_nu_mi_a_placut_la_laboratorul_de_SDA_sau_ce_poate_fi_imbunatatit = "Poate am putea primi mai mult feedback la temele de laborator \nfie cum putem rezolva niste probleme din cod fie cum putem \nimbunatati un cod care functioneaza (eficienta, memorie etc).";
    student.ce_imi_doresc_sa_fac_dupa_ce_termin_facultatea = "Dupa ce termin facultatea mi-ar placea un job in domeniul securitatii cibernetice \nsi ca hobby as vrea sa creez jocuri video.";

    cout<<student.nume<<" "<<student.prenume<<" "<<student.grupa<<"\n\n";
    cout<<student.ce_mi_a_placut_la_laboratorul_de_SDA_si_vreau_sa_fie_pastrat<<"\n\n";
    cout<<student.ce_nu_mi_a_placut_la_laboratorul_de_SDA_sau_ce_poate_fi_imbunatatit<<"\n\n";
    cout<<student.ce_imi_doresc_sa_fac_dupa_ce_termin_facultatea<<"\n";
}
