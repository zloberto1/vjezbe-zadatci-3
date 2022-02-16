#include <iostream>

using namespace std;

struct datum {
    int d, m, g;
};

struct student {
    int IB;
    char ImeiPrezime[30];
    datum rodjenja;
};

void NoviStudent(student* s) {
    cout << "Unesi broj indexa: "; cin >> (*s).IB;
    cout << "Unesi ime i prezime: ";
    cin.ignore();
    cin.getline((*s).ImeiPrezime, sizeof((*s).ImeiPrezime));
    cout << "Unesi dan rodjenja: "; cin >> (*s).rodjenja.d;
    cout << "Unesi mjesec rodjenja: "; cin >> (*s).rodjenja.m;
    cout << "Unesi godinu rodjenja: "; cin >> (*s).rodjenja.g;
    cout << endl;
}

void IspisStudenta(student* s) {
    cout << "Broj indeksa: " << (*s).IB << endl;
    cout << "Ime i prezime: " << (*s).ImeiPrezime << endl;
    cout << "Datum rodjenja: " << (*s).rodjenja.d << "." << (*s).rodjenja.m << "." << (*s).rodjenja.g << "." << endl;
    cout << endl;
}

bool DatumValidan(datum* d) {
    if((*d).g < 1900 || (*d).g > 2100) return false;

    switch((*d).m) {
        case 2: {
            if(((*d).g % 4 == 0 && (*d).g % 100 != 0) || (*d).g % 400 == 0) {
                if((*d).d > 0 && (*d).d < 30) return true;
                else return false;
            } else {
                if((*d).d > 0 && (*d).d < 29) return true;
                else return false;
            }
        }

        case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
            if((*d).d > 0 && (*d).d < 32) return true;
            else return false;
        }

        case 4: case 6: case 9: case 11: {
            if((*d).d > 0 && (*d).d < 31) return true;
            else return false;
        }

        default: {
            return false;
        }
    }
}

int ValidanDatumRodjenja(student* s, int brojStudenata) {
    int temp = 0;
    for(int i = 0; i < brojStudenata; i++) {
        if(!DatumValidan(&(s + i)->rodjenja)) temp++;
    }
    return temp;
}

student* PrviNevazeciDatum(student* s, int brojStudenata) {
    int i;
    for(i = 0; i < brojStudenata; i++) {
        if(!DatumValidan(&(s + i)->rodjenja)) break;
    }
    return s + i;
}

int main()
{
    student* s = new student[5];

    for(int i = 0; i < 5; i++) {
        NoviStudent(&s[i]);
    }

    for(int i = 0; i < 5; i++) {
        IspisStudenta(&s[i]);
    }

    cout << endl;

    if(ValidanDatumRodjenja(s, 5) != 0) {
        cout << "Broj studenata sa nevazecim datumom rodjenja: " << ValidanDatumRodjenja(s, 5) << endl;
        cout << "Prvi student sa nevazecim datumom rodjenja je: " << (*PrviNevazeciDatum(s, 5)).ImeiPrezime << endl;
    } else {
        cout << "Svi datumi rodjenja su validni! " << endl;
    }


    return 0;
}
