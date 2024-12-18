#include <iostream>
using namespace std;

// Klasa Bazowa - Osoba
class Osoba {
  protected:
    string imie;
    string nazwisko;

  public:
    Osoba(string im, string na): imie(im), nazwisko(na) {}
    void przedstaw_sie() {
      cout<<"Nazywam się "<<imie<<" "<<nazwisko<<endl;
    }
};

// Klasa Bazowa - MozeBycStudentem
class MozeBycStudentem {
  public:
    void studiuje(string nazwa_studiow){
      cout<<"Studuje: "<<nazwa_studiow<<endl;
    }
};

// Klasa Bazowa - MozeWykonywacBadania
class MozeWykonywacBadania{
  public:
    void prowadz_badanie(string nazwa_badania){
      cout<<"Prowadzę badanie: "<<nazwa_badania<<endl;
    }
};

// Klasa Bazowa - MozeNauczac
class MozeNauczac{
  public:
    void prowadz_zajecia(string nazwa_przedmiotu){
      cout<<"Mogę prowadzić zajęcia z "<<nazwa_przedmiotu<<endl;
    }
};

// Klasa Potomna - TStudent
class TStudent: public Osoba, public MozeBycStudentem {
  private:
    int nr_indeksu;

  public:
    TStudent(string im, string na, int indeks): Osoba(im,na), nr_indeksu(indeks) {}
    void podaj_nr_indeksu(){
      cout<<"Numer indeksu: "<<nr_indeksu<<endl;
    }
};

// Klasa Potomna - TDoktorant
class TDoktorant: public TStudent {
  private:
    string temat_pracy;

  public:
    TDoktorant(string im, string na, int indeks, string temat): TStudent(im, na, indeks), temat_pracy(temat) {}
    void przedstaw_temat_pracy(){
      cout<<"Temat pracy doktorskiej: "<<temat_pracy<<endl;
    }
};

// Klasa Potomna - TDoktorantNaucz
class TDoktorantNaucz: public TDoktorant, public MozeNauczac {
  private:
    string wyklad;

  public:
    TDoktorantNaucz(string im, string na, int indeks, string temat, string wyk): TDoktorant(im, na, indeks, temat), wyklad(wyk) {}
    void przedstaw_wyklad(){
      cout<<"Mogę nauczać: "<<wyklad<<endl;
    }
};

// Klasa Potomna - TAsystentBadan
class TAsystentBadan: public MozeWykonywacBadania, public Osoba {
  private:
    string doswiadczenie;

  public:
    TAsystentBadan(string im, string na, string dosw): Osoba(im, na), doswiadczenie(dosw) {}
    void przedstaw_doswiadczenie(){
      cout<<"Mogę asystować przy badaniu: "<<doswiadczenie<<endl;
    }
};

//Klasa Potomna - TDoktorantBadacz
class TDoktorantBadacz: public TDoktorant, public TAsystentBadan {
  public:
    TDoktorantBadacz(string im, string na, int indeks, string temat, string dosw): TDoktorant(im, na, indeks, temat), TAsystentBadan(im, na, dosw) {}
    void przedstaw_sie(){
      TDoktorant::przedstaw_sie();
    }
};

int main() {
  TStudent student("Janusz", "Prutowski", 1619491);
  student.przedstaw_sie();
  student.studiuje("Informatyka Stomowana");
  student.podaj_nr_indeksu();
  cout<<endl;

  TDoktorant doktorant("Michał", "Lewandowski", 5432167, "Biokompozyty chitozanowo-srebrowe - otrzymywanie i charakterystyka fizykochemiczna.");
  doktorant.przedstaw_sie();
  doktorant.podaj_nr_indeksu();
  doktorant.przedstaw_temat_pracy();
  cout<<endl;

  TDoktorantNaucz doktorant_nauczyciel("Kamil", "Nowicki", 6789034, "Inny temat", "Fizyka");
  doktorant_nauczyciel.przedstaw_sie();
  doktorant_nauczyciel.podaj_nr_indeksu();
  doktorant_nauczyciel.przedstaw_temat_pracy();
  doktorant_nauczyciel.przedstaw_wyklad();
  cout<<endl;

  TDoktorantBadacz doktorant_badacz("Anna", "Wiśniewska", 35482866, "Badanie dyfuzji powierzchniowej ftalocyjaniny z wbudowanym atomem miedzi po powierzchni srebra (100)", "Teoria i fenomenologia oddziaływań fundamentalnych z uwzględnieniem eksperymentów fizyki cząstek elementarnych");
  doktorant_badacz.przedstaw_sie();
  doktorant_badacz.podaj_nr_indeksu();
  doktorant_badacz.przedstaw_temat_pracy();
  doktorant_badacz.przedstaw_doswiadczenie();
}