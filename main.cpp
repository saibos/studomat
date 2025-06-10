
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Struktura za jednog studenta
struct Student {
    string ime;
    string prezime;
    string jmbg;
    int godina;
};

// Funkcija za unos studenta
void dodajStudenta() {
    Student s;
    cout << "Unesi ime: ";
    getline(cin, s.ime);
    cout << "Unesi prezime: ";
    getline(cin, s.prezime);
    cout << "Unesi JMBG: ";
    getline(cin, s.jmbg);
    cout << "Unesi godinu studija: ";
    cin >> s.godina;
    cin.ignore(); // da ne preskoči sljedeći unos

    // Spremi u fajl
    ofstream fajl("studenti.txt", ios::app);
    if (fajl.is_open()) {
        fajl << s.ime << "," << s.prezime << "," << s.jmbg << "," << s.godina << endl;
        fajl.close();
        cout << "Student uspješno dodan.\n";
    } else {
        cout << "Greška pri otvaranju fajla.\n";
    }
}

// Funkcija za prikaz svih studenata
void prikaziStudente() {
    ifstream fajl("studenti.txt");
    string linija;
    cout << "\nPopis studenata:\n";
    while (getline(fajl, linija)) {
        cout << linija << endl;
    }
    fajl.close();
}

// Funkcija za pretragu po prezimenu
void pretraziPoPrezimenu() {
    string trazenoPrezime;
    cout << "Unesi prezime za pretragu: ";
    getline(cin, trazenoPrezime);

    ifstream fajl("studenti.txt");
    string linija;
    bool pronadjen = false;
    while (getline(fajl, linija)) {
        if (linija.find(trazenoPrezime) != string::npos) {
            cout << linija << endl;
            pronadjen = true;
        }
    }
    fajl.close();

    if (!pronadjen) {
        cout << "Nema studenata s tim prezimenom.\n";
    }
}

int main() {
    int izbor;
    do {
        // Glavni izbornik
        cout << "\n==== STUDOMAT ====" << endl;
        cout << "1. Dodaj studenta" << endl;
        cout << "2. Prikazi sve studente" << endl;
        cout << "3. Pretraga po prezimenu" << endl;
        cout << "4. Izlaz" << endl;
        cout << "Odabir: ";
        cin >> izbor;
        cin.ignore(); // da se omogući unos stringova nakon int-a

        switch (izbor) {
            case 1:
                dodajStudenta();
                break;
            case 2:
                prikaziStudente();
                break;
            case 3:
                pretraziPoPrezimenu();
                break;
            case 4:
                cout << "Izlaz iz programa..." << endl;
                break;
            default:
                cout << "Neispravan unos, pokušaj ponovno.\n";
        }
    } while (izbor != 4);

    return 0;
}
