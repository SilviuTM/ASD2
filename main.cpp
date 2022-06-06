#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <conio.h>
#include <iomanip>
#include <string.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

void CLEAR(void) // Clear screen regardles of host OS
{
    system("cls||clear");
    return;
}

typedef struct tabel
{
    std::string nume;
    std::vector<std::string> campuri;         // camp1;camp2;camp3;...
    std::vector<std::vector<std::string>> obiecte; // obiecte[i] e obiectul pe care il vrei
                                    // obiecte[i][j] e campul pe care il vrei de la obiecte[i]
} Tabel;
std::vector<Tabel> tabele;

void StergereCamp(/**/)
{
    std::string sterg, numele;
    std::cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        std::cout << tabele.at(i).nume << '\n';
    }
    std::cout << "Din ce tablou doresti sa stergi: ";
    std::getline(std::cin, numele);
    std::cout << "Campuri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].campuri.size(); j++)
            {
                std::cout << tabele[i].campuri[j] << std::endl;
            }
        }
    }
    std::cout << "Ce camp doriti sa stergeti: ";
    std::getline(std::cin, sterg);
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

void StergereObiect(/**/)
{
    std::string numele;
    std::cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        std::cout << tabele.at(i).nume << '\n';
    }
    std::cout << "Din ce tablou doresti sa stergi: ";
    std::getline(std::cin, numele);
    std::cout << "obiecte:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].obiecte.size(); j++)
            {
                for (int l = 0; l < tabele[i].obiecte[j].size(); l++)
                {
                    std::cout << tabele[i].obiecte[j][l] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    std::cout << "Introduceti linia obiectului pe care il vreti sa-l stergeti: ";
    int linie;
    std::cin >> linie;
    linie -= 1;
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

void ActualizareObiect(/**/) {
    std::string numele;
    std::cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        std::cout << tabele.at(i).nume << '\n';
    }
    std::cout << "Din ce tablou doresti sa actualizezi: ";
    std::getline(std::cin, numele);
    std::cout << "obiecte:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].obiecte.size(); j++)
            {
                for (int l = 0; l < tabele[i].obiecte[j].size(); l++)
                {
                    std::cout << tabele[i].obiecte[j][l] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    std::cout << "Introduceti linia si coloana obiectului pe care il vreti sa-l actualizezi: ";
    int linie, coloana, i;
    std::cin >> linie >> coloana;
    linie -= 1;
    coloana -= 1;
    for (i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
            break;
    }
    for (int j = 0; j < tabele[i].obiecte.size(); j++)
        {
            if (j == linie)
            {
                for(int k = 0; k < tabele[i].obiecte[j].size(); k++)
                {
                    if(k == coloana)
                    {
                        std::cout << "Introduceti noul obiect [" << tabele[i].obiecte[j][k] << "]: ";
                        std::string nou;
                        fflush(stdin);
                        std::getline(std::cin, nou);
                        tabele[i].obiecte[j][k] = nou;
                    }
                }
            }
        }
}

void CautareObiect(/**/)
{
    std::string numele;
    std::cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
        std::cout << tabele.at(i).nume << '\n';

    std::cout << "In ce tablou doresti sa cauti: ";
    std::getline(std::cin, numele);
    std::cout << "obiecte:\n";
    for (int i = 0; i < tabele.size(); i++)
        if (tabele[i].nume == numele)
        {
            std::vector<std::string> criterii;
            for (int temp = 0; temp < tabele[i].campuri.size(); temp++)
                criterii.push_back("-");

            int cursor = 0;
            int c;
            std::string alegere;
            do
            {
                CLEAR();
                do
                {
                    // afisare submeniu
                    for(int temp = 0; temp < tabele[i].campuri.size(); temp++){
                        if(temp == cursor) 
                            std::cout << ">>";
                        std::cout << "Cautare dupa " << tabele[i].campuri[temp] << std::endl;
                    }

                    /// verificare + afisare criterii
                    int c_active = 0;
                    for(int temp = 0; temp < tabele[i].campuri.size(); temp++)
                        if(criterii[temp] != "-")
                            c_active++;

                    if(c_active == 0)
                        std::cout << "Nu exista criterii active!" << std::endl;
                    else
                        std::cout << "Criterii active:" << std::endl;

                    for(int temp = 0; temp < tabele[i].campuri.size(); temp++)
                        if(criterii[temp] != "-")
                            std::cout << tabele[i].campuri[temp] << ": " << criterii[temp] << std::endl;

                    std::fflush(stdin);
                    c = getch();
                    if (c == KEY_UP)
                    {
                        cursor--;
                        if (cursor == -1)
                            cursor = tabele[i].campuri.size() - 1;
                    }
                    else if (c == KEY_DOWN)
                    {
                        cursor++;
                        if (cursor == tabele[i].campuri.size())
                            cursor = 0;
                    }
                    else if (c == ENTER)
                        break;
                }
                while(1);
                
                std::cout << "Input " << tabele[i].campuri[cursor] << "(input "-" to disable this criteria): ";
                std::getline(std::cin, criterii[cursor]);
                
                /// verificare cate masini indeplinesc conditia
                bool exists = false;
                for(auto&obiect:tabele[i].obiecte)
                {
                    bool ok = true;
                    for(int temp = 0; temp < tabele[i].campuri.size(); temp++)
                    {
                        if(criterii[temp] != "-" && obiect[temp].find(criterii[temp]) == std::string::npos)
                            ok = false;
                        
                        if(ok)
                            exists = true;
                    }

                }

                if (exists)
                {
                    for(auto&camp:tabele[i].campuri)
                        std::cout << camp << ";";
                    std::cout << std::endl;

                    for(auto&obiect:tabele[i].obiecte)
                    {
                        bool ok = true;

                        for(int temp = 0; temp < tabele[i].campuri.size(); temp++)
                            if(criterii[temp] != "-" && obiect[temp].find(criterii[temp]) == std::string::npos)
                                ok = false;

                        if(ok)
                        {
                            for(auto&parametru:obiect)
                                std::cout << parametru << ";";
                            std::cout << std::endl;
                        }
                    }
                }
                else
                    std::cout << "Nu s-au gasit intrari aferente criteriilor!" << std::endl;

                std::cout << "Doriti sa mai modificati/adaugati criterii? [Y/N]: ";
                std::getline(std::cin, alegere);
            } while (alegere == "Y" || alegere == "y");
        }
}

void CitireDate()
{
    std::ifstream fin("ASD.txt");
    std::string line, word, nume;
    int nr;

    while (std::getline(fin, nume))
    {
        Tabel tabel;
        tabel.nume = nume;
        fin >> nr;
        fin.ignore();

        // citire campuri
        std::getline(fin, line);
        std::stringstream str(line);
        while (std::getline(str, word, ';'))
            tabel.campuri.push_back(word);

        // citire obiecte
        while (nr != 0)
        {
            nr--;

            std::getline(fin, line);
            std::vector<std::string> aux;
            std::stringstream str(line);
            while (std::getline(str, word, ';'))
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
    std::cout << "Introduceti numele tabelului in care doriti sa adaugati un nou obiect" << '\n';
    for (auto &i : tabele)
        std::cout << i.nume << '\n';
    std::string nume;
    std::getline(std::cin, nume);
    for (auto &tabel : tabele)
    {
        if (nume == tabel.nume)
        {
            int nrcamp = tabel.campuri.size();
            std::vector<std::string> obiect;
            for (int j = 1; j <= nrcamp; j++)
            {
                std::cout << tabel.campuri[j - 1] << ": ";
                std::string atribut;
                std::getline(std::cin, atribut);
                std::cout << '\n';
                obiect.push_back(atribut);
            }
            tabel.obiecte.push_back(obiect);
        }
    }
}

void CreareTabel()
{
    Tabel tabel;
    std::string nume;
    std::cout << "Introduceti numele tabelului" << '\n';
    std::getline(std::cin, nume);
    tabel.nume = nume;
    std::cout << "Introduceti cate campuri doriti sa aiba tabelul" << '\n';
    int n;
    std::cin >> n;
    std::cout << "Introduceti cum sa se numeasca campurile" << '\n';
    std::cin.get();
    for (int i = 1; i <= n; i++)
    {
        std::string camp;
        std::getline(std::cin, camp);
        tabel.campuri.push_back(camp);
    }
    std::cout << "Introduceti numarul obiectelor" << '\n';
    int m;
    std::cin >> m;
    std::cin.get();
    for (int i = 1; i <= m; i++)
    {
        std::cout << "Introduceti atributele pentru noul obiect" << '\n';
        std::vector<std::string> obiect;
        for (int j = 1; j <= n; j++)
        {
            std::cout << tabel.campuri[j - 1] << ": ";
            std::string atribut;
            std::getline(std::cin, atribut);
            std::cout << '\n';
            obiect.push_back(atribut);
        }
        tabel.obiecte.push_back(obiect);
    }
    tabele.push_back(tabel);
}

void ModificareNumeTabel()
{
    std::string numele;
    std::cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        std::cout << tabele.at(i).nume << '\n';
    }
    std::cout << "Ce tablou doriti sa modificati: ";
    std::getline(std::cin, numele);
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            std::getline(std::cin, tabele[i].nume);
            return;
        }
    }
}

void AdaugareCamp(/**/)
{
    std::string adaug, numele;
    std::cout << "Ce camp doresti sa adaugi: ";
    std::getline(std::cin, adaug);
    std::cout << "Tablourile:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        std::cout << "\033[1;34m" << tabele.at(i).nume << "\033[0m" << '\n';
    }
    std::cout << "In ce tablou doresti sa adaugi campul din cele afisate de mai sus: ";
    std::getline(std::cin, numele);
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            tabele[i].campuri.push_back(adaug);
            for (int j = 0; j < tabele[i].obiecte.size(); j++)
            {
                std::string adaug2;
                std::cout << "Introdu informatia pentru campul adaugat al obiectului " << "\033[1;36m" << j << "\033[0m" << " ";
                std::getline(std::cin, adaug2);
                tabele[i].obiecte[j].push_back(adaug2);
            }
        }
    }
}

void AfisareCampuri(/**/)
{
    std::string numeTabel;
    std::cout << "Introduceti numele tabelului al carui campuri doriti sa le afisati:" << '\n';
    for (auto &i : tabele)
        std::cout <<  "\033[1;34m" << i.nume << "\033[0m" << '\n';
    std::getline(std::cin, numeTabel);
    for (auto &i : tabele)
        if (numeTabel == i.nume)
        {
            for (auto &j : i.campuri)
            std::cout << "- " << "\033[1;36m" << j << "\033[0m" << "\n";
        }
}

void ModificareNumeCamp()
{
    std::string sterg, numele;
    std::cout << "Tablouri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        std::cout << tabele.at(i).nume << '\n';
    }
    std::cout << "Din ce tablou doresti sa modificati: ";
    std::getline(std::cin, numele);
    std::cout << "Campuri:\n";
    for (int i = 0; i < tabele.size(); i++)
    {
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].campuri.size(); j++)
            {
                std::cout << tabele[i].campuri[j] << std::endl;
            }
        }
    }
    std::cout << "Ce camp doriti sa modificati: ";
    std::getline(std::cin, sterg);
    for (int i = 0; i < tabele.size(); i++)
        if (tabele[i].nume == numele)
        {
            for (int j = 0; j < tabele[i].campuri.size(); j++)
            {
                if (tabele[i].campuri[j] == sterg)
                    std::cout << "\nIntroduceti noul nume: "; std::getline(std::cin, tabele[i].campuri[j]);
            }
        }
}

void AfisareTabel()
{
    std::string numeTabel;
    std::cout << "Introduceti numele tabelului pe care doriti sa il afisati:" << '\n';
    for (auto &i : tabele)
        std::cout <<  "\033[1;34m" << i.nume << "\033[0m" << '\n';
    std::getline(std::cin, numeTabel);
    for (auto &i : tabele)
        if (numeTabel == i.nume)
        {
            for (auto &j : i.campuri)
            std::cout << "\033[1;36m" << j << "\033[0m" << " ";
            std::cout << '\n';

            for (auto &k : i.obiecte)
            {
                for (auto &l : k)
                std::cout << "\033[1;35m" << l << "\033[0m" << " ";
                std::cout << '\n';
            }
        }
}

void ScriereDate()
{
    std::ofstream out("ASD.txt");
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
        std::cout <<  "\033[1;34m" << i.nume << "\033[0m" << '\n';
        for (auto &j : i.campuri)
            std::cout << "\033[1;36m" << std::setw(20) << j << std::setw(0) << "\033[0m" << " | ";
        std::cout << '\n';
        for (auto &k : i.obiecte)
        {
            for (auto &l : k)
                std::cout << "\033[1;35m" << std::setw(20) << l << std::setw(0) << "\033[0m" << " | ";
            std::cout << '\n';
        }
    }
}

void StergereTabel()
{
    std::cout << "Introduceti numele tabelului pe care doriti sa il stergeti:" << '\n';
    for (auto &i : tabele)
        std::cout <<  "\033[1;34m" << i.nume << "\033[0m" << '\n';

    std::string nume;
    std::getline(std::cin, nume);
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
            std::cout << ">>";
        std::cout << "Creare tabel nou" << std::endl;
        if (cursor == 1)
            std::cout << ">>";
        std::cout << "Stergere tabel" << std::endl;
        if (cursor == 2)
            std::cout << ">>";
        std::cout << "Afisare tabel" << std::endl;
        if (cursor == 3)
            std::cout << ">>";
        std::cout << "Adaugare camp" << std::endl;
        if (cursor == 4)
            std::cout << ">>";
        std::cout << "Stergere camp" << std::endl;
        if (cursor == 5)
            std::cout << ">>";
        std::cout << "Adaugare obiect" << std::endl;
        if (cursor == 6)
            std::cout << ">>";
        std::cout << "Stergere obiect" << std::endl;
        if (cursor == 7)
            std::cout << ">>";
        std::cout << "Actualizare obiect" << std::endl;
        if (cursor == 8)
            std::cout << ">>";
        std::cout << "Cautare obiecte" << std::endl;
        if (cursor == 9)
            std::cout << ">>";
        std::cout << "Afisare baza de date" << std::endl;
        if (cursor == 10)
            std::cout << ">>";
        std::cout << "Iesire" << std::endl;

        std::fflush(stdin);
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
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 1:
                StergereTabel();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 2:
                AfisareTabel();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 3:
                AdaugareCamp();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 4:
                StergereCamp();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 5:
                AdaugareObiect();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 6:
                StergereObiect();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 7:
                ActualizareObiect();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 8:
                CautareObiect();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 9:
                AfisareBazaDate();
                std::fflush(stdin);
                std::cout << "Apasa " << "\033[1;32m" << "Enter" << "\033[0m" <<" pentru a continua!";
                getch();
                break;
            case 10:
                return;
            }

        ScriereDate();
    } while (true);
}

int main()
{
    CitireDate();
    MeniuPrincipal();
    return 0;
}
