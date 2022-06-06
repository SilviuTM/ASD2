#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

void CLEAR(void) // Clear screen regardles of host OS
{
    system("cls||clear");
    return;
}

using namespace std;

typedef struct tabel
{
    string nume;
    vector<string> campuri;         // camp1;camp2;camp3;...
    vector<vector<string>> obiecte; // obiecte[i] e obiectul pe care il vrei
                                    // obiecte[i][j] e campul pe care il vrei de la obiecte[i]
} Tabel;
vector<Tabel> tabele;

// void CreareTabel(/**/){}
// void StergereTabel(/**/){}
// void AfisareTabel(/**/){}

void StergereCamp(/*Stun Seed*/)
{
    string sterg, numele;
    cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        cout << tabele.at(i).nume << '\n';
    }
    cout << "Din ce tablou doresti sa stergi: ";
    getline(cin, numele);
    cout << "Campuri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].campuri.size(); j++)
            {
                cout << tabele[i].campuri[j] << endl;
            }
        }
    }
    cout << "Ce camp doriti sa stergeti: ";
    getline(cin, sterg);
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {

            for (int j = 0; j < tabele[i].campuri.size(); j++)
            {
                if (tabele[i].campuri[j] == sterg)
                {
                    tabele[i].campuri.erase(tabele[i].campuri.begin() + j);
                    for (int l = 0; l < tabele[i].obiecte.size(); l++)
                    {
                        tabele[i].obiecte[l].erase(tabele[i].obiecte[l].begin() + j);
                    }
                }
            }
        }
    }
}
// void AdaugareObiect(/**/){}
void StergereObiect(/*delete this*/)
{
    string numele;
    cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        cout << tabele.at(i).nume << '\n';
    }
    cout << "Din ce tablou doresti sa stergi: ";
    getline(cin, numele);
    cout << "obiecte:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].obiecte.size(); j++)
            {
                for (int l = 0; l < tabele[i].obiecte[j].size(); l++)
                {
                    cout << tabele[i].obiecte[j][l] << " ";
                }
                cout << endl;
            }
        }
    }
    cout << "Introduceti linia obiectului pe care il vreti sa-l stergeti: ";
    int linie;
    cin >> linie;
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].obiecte.size(); j++)
            {
                if (j == linie)
                {
                    tabele[i].obiecte.erase(tabele[i].obiecte.begin() + j);
                }
            }
        }
    }
}
void ActualizareObiect(/**/) {}
void CautareObiect(/**/) {}
// void AfisareBazaDate(/**/){}
// void CitireDate()
void CitireDate()
{
    ifstream fin("ASD.txt");
    string line, word, nume;
    int nr;

    while (getline(fin, nume))
    {
        Tabel tabel;
        tabel.nume = nume;
        fin >> nr;
        fin.ignore();

        // citire campuri
        getline(fin, line);
        stringstream str(line);
        while (getline(str, word, ';'))
            tabel.campuri.push_back(word);

        // citire obiecte
        while (nr != 0)
        {
            nr--;

            getline(fin, line);
            vector<string> aux;
            stringstream str(line);
            while (getline(str, word, ';'))
                aux.push_back(word);

            tabel.obiecte.push_back(aux);
        }

        // adaugare tabel
        tabele.push_back(tabel);
    }

    fin.close();
}

void AdaugareObiect()
{
    cout << "Introduceti numele tabelului in care doriti sa adaugati un nou obiect" << '\n';
    for (auto &i : tabele)
        cout << i.nume << '\n';
    string nume;
    getline(cin, nume);
    for (auto &tabel : tabele)
    {
        if (nume == tabel.nume)
        {
            int nrcamp = tabel.campuri.size();
            vector<string> obiect;
            for (int j = 1; j <= nrcamp; j++)
            {
                cout << tabel.campuri[j - 1] << ": ";
                string atribut;
                getline(cin, atribut);
                cout << '\n';
                obiect.push_back(atribut);
            }
            tabel.obiecte.push_back(obiect);
        }
    }
}

void CreareTabel()
{
    Tabel tabel;
    string nume;
    cout << "Introduceti numele tabelului" << '\n';
    getline(cin, nume);
    tabel.nume = nume;
    cout << "Introduceti cate campuri doriti sa aiba tabelul" << '\n';
    int n;
    cin >> n;
    cout << "Introduceti cum sa se numeasca campurile" << '\n';
    cin.get();
    for (int i = 1; i <= n; i++)
    {
        string camp;
        getline(cin, camp);
        tabel.campuri.push_back(camp);
    }
    cout << "Introduceti numarul obiectelor" << '\n';
    int m;
    cin >> m;
    cin.get();
    for (int i = 1; i <= m; i++)
    {
        cout << "Introduceti atributele pentru noul obiect" << '\n';
        vector<string> obiect;
        for (int j = 1; j <= n; j++)
        {
            cout << tabel.campuri[j - 1] << ": ";
            string atribut;
            getline(cin, atribut);
            cout << '\n';
            obiect.push_back(atribut);
        }
        tabel.obiecte.push_back(obiect);
    }
    tabele.push_back(tabel);
}
void AdaugareCamp(/*wHAT*/)
{
    string adaug, numele;
    cout << "Ce camp doresti sa adaugi: ";
    getline(cin, adaug);
    cout << "Tablourile:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        cout << tabele.at(i).nume << '\n';
    }
    cout << "In ce tablou doresti sa adaugi campul din cele afisate de mai sus: ";
    getline(cin, numele);
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            tabele[i].campuri.push_back(adaug);
            for (int j = 0; j < tabele[i].obiecte.size(); j++)
            {
                string adaug2;
                cout << "Introdu informatia pentru campul adaugat al obiectului " << j << " ";
                getline(cin, adaug2);
                tabele[i].obiecte[j].push_back(adaug2);
            }
        }
    }
}

void AfisareTabel()
{
    string numeTabel;
    cout << "Introduceti numele tabelului pe care doriti sa il afisati:" << '\n';
    for (auto &i : tabele)
        cout << i.nume << '\n';
    getline(cin, numeTabel);
    for (auto &i : tabele)
        if (numeTabel == i.nume)
        {
            for (auto &j : i.campuri)
                cout << j << " ";
            cout << '\n';

            for (auto &k : i.obiecte)
            {
                for (auto &l : k)
                    cout << l << " ";
                cout << '\n';
            }
        }
}

void ScriereDate()
{
    ofstream out("ASD.txt");
    for (auto &tabel : tabele) // fiecare tabel
    {
        out << tabel.nume << '\n';
        out << tabel.obiecte.size() << '\n';
        for (auto &camp : tabel.campuri) // fiecare camp
        {
            out << camp << ";";
        }
        out << '\n';
        for (auto &obiect : tabel.obiecte) // cauta in fiecare obiect
        {
            for (auto &atribut : obiect)
                out << atribut << ";";
            out << '\n';
        }
    }

    out.close();
}

void AfisareBazaDate()
{
    for (auto &i : tabele)
    {
        for (auto &j : i.campuri)
            cout << j << " ";
        cout << '\n';
        for (auto &k : i.obiecte)
        {
            for (auto &l : k)
                cout << l << " ";
            cout << '\n';
        }
    }
}

void StergereTabel()
{
    cout << "Introduceti numele tabelului pe care doriti sa il stergeti:" << '\n';
    for (auto &i : tabele)
        cout << i.nume << '\n';

    string nume;
    getline(cin, nume);
    for (int i = 0; i < (int)tabele.size(); i++)
        if (tabele[i].nume == nume)
            tabele.erase(tabele.begin() + i);
}

void MeniuPrincipal()
{
    int cursor = 0;
    int c;

    do
    {
        CLEAR();
        if (cursor == 0)
            cout << ">>";
        cout << "Creare tabel nou" << endl;
        if (cursor == 1)
            cout << ">>";
        cout << "Stergere tabel" << endl;
        if (cursor == 2)
            cout << ">>";
        cout << "Afisare tabel" << endl;
        if (cursor == 3)
            cout << ">>";
        cout << "Adaugare camp" << endl;
        if (cursor == 4)
            cout << ">>";
        cout << "Stergere camp" << endl;
        if (cursor == 5)
            cout << ">>";
        cout << "Adaugare obiect" << endl;
        if (cursor == 6)
            cout << ">>";
        cout << "Stergere obiect" << endl;
        if (cursor == 7)
            cout << ">>";
        cout << "Actualizare obiect" << endl;
        if (cursor == 8)
            cout << ">>";
        cout << "Cautare obiecte" << endl;
        if (cursor == 9)
            cout << ">>";
        cout << "Afisare baza de date" << endl;
        if (cursor == 10)
            cout << ">>";
        cout << "Iesire" << endl;

        fflush(stdin);
        c = getch();
        if (c == KEY_UP)
        {
            cursor--;
            if (cursor == -1)
                cursor = 10;
        }
        else if (c == KEY_DOWN)
        {
            cursor++;
            if (cursor == 11)
                cursor = 0;
        }
        else if (c == ENTER) /// verifica functionalitate cross platform
            switch (cursor)
            {
            case 0:
                CreareTabel();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 1:
                StergereTabel();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 2:
                AfisareTabel();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 3:
                AdaugareCamp();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 4:
                StergereCamp();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 5:
                AdaugareObiect();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 6:
                StergereObiect();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 7:
                ActualizareObiect();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 8:
                CautareObiect();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 9:
                AfisareBazaDate();
                fflush(stdin);
                cout << "Apasa Enter pentru a continua!";
                getch();
                break;
            case 10:
                return;
            }

        ScriereDate();
    } while (1);
}