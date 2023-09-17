#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    double galutinis;
};

double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return (sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0;
    }
    else {
        return sortedGrades[size / 2];
    }
}

int main() {
    int skaicius, skaicius1;

   
    cout << "Pasirinkite norima skaiciu studentu. Iveskite ju skaiciu(naudoti tik skaicius): ";
    while (!(cin >> skaicius) || skaicius <= 0) {
        cout << "Neteisingai ivedete skaiciu, pakartokite norima skaiciu ivesdami skaitmenis ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Iveskite kiek studentas tures namų darbų, tai yra kiek gaus pazymiu, kiekvienas pazymis atspindi viena namu darba : ";
    while (!(cin >> skaicius1) || skaicius1 <= 0) {
        cout << "Neteisingai ivedete skaiciu. Prasome per nauja ivesti skaiciu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    
    string header;
    string choice;

    do {
        cout << "Prasome pasirinkti ka norite skaiciuoti vidurki ar mediana. Parasykite('Vidurkis') arba ('Mediana'):";
        cin >> choice;

        if (choice == "Vidurkis") {
            header = "Galutinis(vid.)";
        }
        else if (choice == "Mediana") {
            header = "Galutinis(med.)";
        }
        else {
            cout << "Neteisinga pasirinkimas! Bandykite dar karta." << endl;
        }

    } while (choice != "Vidurkis" && choice != "Mediana");

   

    vector<Studentas> studentai;

    // Studento duomenys
    for (int j = 0; j < skaicius; j++) {
        Studentas s;
        vector<int> pazymiai;
        int suma = 0;

        
        bool teisingasVardas = false;
        while (!teisingasVardas) {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes varda: ";
            cin >> s.vardas;

            teisingasVardas = true;
            for (char c : s.vardas) {
                if (!isalpha(c)) {
                    teisingasVardas = false;
                    cout << "Neteisingai ivedete varda. Vardas turi buti tik is raidziu." << endl;
                    break;
                }
            }
        }



        bool teisingaPavarde = false;
        while (!teisingaPavarde) {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes  pavarde: ";
            cin >> s.pavarde;

            teisingaPavarde = true;
            for (char c : s.pavarde) {
                if (!isalpha(c)) {
                    teisingaPavarde = false;
                    cout << "Neteisingai ivedete pavarde. Pavarde turi buti  tik is raidziu." << endl;
                    break;
                }

            }
        }









       
        cout << "Įveskite " << j + 1 << "-ojo studento pažymius (dešimtbalė sistema):" << endl;
        for (int i = 0; i < skaicius1; ) {
            int pazymys;
            cin >> pazymys;

            if (pazymys < 1 || pazymys > 10) {
                cout << "Neteisinga įvesta. Prašome įvesti pažymį nuo 1 iki 10: ";
            }
            else {
                pazymiai.push_back(pazymys);
                suma += pazymys;
                i++;
            }
        }

        
        cout << "Įveskite " << j + 1 << "-ojo studento egzamino rezultata nuo 1 iki 10:" << endl;
        int egzaminas;
        cin >> egzaminas;
        while (egzaminas < 1 || egzaminas > 10) {
            cout << "Neteisinga įvesta. Prašome įvesti egzamino rezultata nuo 1 iki 10: ";
            cin >> egzaminas;
        }

        
        if (choice == "Vidurkis") {
            s.galutinis = (static_cast<double>(suma) / skaicius1) * 0.4 + egzaminas * 0.6;
        }
        else if (choice == "Mediana") {
            s.galutinis = calculateMedian(pazymiai) * 0.4 + egzaminas * 0.6;
        }

        studentai.push_back(s);
    }

    
    cout << fixed << setprecision(2);
    cout << setw(20) << left << "Pavarde"
        << setw(20) << left << "Vardas"
        << setw(20) << left << header << endl;
    cout << "________________________________________________________________________" << endl;

    for (const Studentas& s : studentai) {
        cout << setw(20) << left << s.pavarde
            << setw(20) << left << s.vardas
            << setw(20) << left << s.galutinis << endl;
    }

    return 0;
}
