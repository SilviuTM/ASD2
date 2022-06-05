#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

void CLEAR(void) //Clear screen regardles of host OS
{
    system("cls||clear");
    return;
}

using namespace std;

typedef struct tabel
{
    string nume;
    vector<string> campuri; // camp1;camp2;camp3;...
    vector<vector<string>> obiecte; // obiecte[i] e obiectul pe care il vrei
                                    // obiecte[i][j] e campul pe care il vrei de la obiecte[i]
}Tabel;
vector<Tabel> tabele;

//void CreareTabel(/**/){}
//void StergereTabel(/**/){}
//void AfisareTabel(/**/){}
void AdaugareCamp(/**/){}
void StergereCamp(/**/){}
void AdaugareObiect(/**/){}
void StergereObiect(/**/){}
void ActualizareObiect(/**/){}
void CautareObiect(/**/){}
//void AfisareBazaDate(/**/){}
//void CitireDate()
void CitireDate()
{
    ifstream fin("ASD.txt");
    string line, word;
    int nr;

    while(fin.peek() != fin.eof())
    {
        Tabel tabel;
        getline(fin, tabel.nume);
        fin >> nr;

        // citire campuri
        getline(fin, line);
        stringstream str(line);
        while(getline(str, word, ';'))
            tabel.campuri.push_back(word);

        // citire obiecte
        while(nr != 0)
        {
            nr--;

            getline(fin, line);
            vector<string> aux;
            stringstream str(line);
            while(getline(str, word, ';'))
                aux.push_back(word);

            tabel.obiecte.push_back(aux);
        }

        // adaugare tabel
        tabele.push_back(tabel);
    }
}

void CreareTabel()
{
    Tabel tabel;
    string nume;
    cout<<"Introduceti numele tabelului"<<'\n';
    getline(cin,nume);
    tabel.nume=nume;
    cout<<"Introduceti cate campuri doriti sa aiba tabelul"<<'\n';
    int n;
    cin>>n;
    cout<<"Introduceti cum sa se numeasca campurile"<<'\n';
    for(int i=1;i<=n;i++)
    {
        string camp;
        getline(cin,camp);
        tabel.campuri.push_back(camp);
    }
    cout<<"Introduceti numarul obiectelor"<<'\n';
    int m;
    cin>>m;

    for(int i=1;i<=m;i++)
    {
        cout<<"Introduceti atributele pentru noul obiect"<<'\n';
        vector<string> obiect;
        for(int j=1;j<=n;j++)
        {
            cout<<tabel.campuri[j-1]<<": ";
            string atribut;
            getline(cin,atribut);
            cout<<'\n';
           obiect.push_back(atribut);
        }
      tabel.obiecte.push_back(obiect);
    }
    tabele.push_back(tabel);
}


void AfisareTabel()
{
    string numeTabel;
    cout<<"Introduceti numele tabelului pe care doriti sa il afisati:"<<'\n';
    for(auto&i:tabele)
        cout<<i.nume<<'\n';
    getline(cin,numeTabel);
    for(auto&i:tabele)
        if(numeTabel==i.nume)
        {
            for(auto&j:i.campuri)
                cout<<j<<" ";
            cout<<'\n';

            for(auto&k:i.obiecte)
            {
                for(auto&l:k)
                    cout<<l<<" ";
                cout<<'\n';
            }
        }
}

void ScriereDate()
{
    ofstream out("ASD.txt");
    for(auto&tabel:tabele)//fiecare tabel
    {
        out<<tabel.nume<<'\n';
        out<<tabel.obiecte.size()<<'\n';
        for(auto&camp:tabel.campuri)//fiecare camp
        {
            out<<camp<<";";
        }
        out<<'\n';
        for(auto&obiect:tabel.obiecte)//cauta in fiecare obiect
        {
            for(auto&atribut:obiect)
                out<<atribut<<";";
        out<<'\n';
         }
    }
}
void AfisareBazaDate()
{

    string numeTabel;
    cout<<"Introduceti numele tabelului pe care doriti sa il afisati:"<<'\n';
    for(auto&i:tabele)
        cout<<i.nume<<'\n';
    cin>>numeTabel;
    for(auto&i:tabele)
    {
        for(auto&j:i.campuri)
            cout<<j<<" ";
        cout<<'\n';
        for(auto&k:i.obiecte)
        {
            for(auto&l:k)
                cout<<l<<" ";
            cout<<'\n';
        }
    }
}


void StergereTabel() {
    cout<<"Introduceti numele tabelului care doriti sa fie sters: ";
    string nume;
    getline(cin, nume);
    for(int i = 0; i < tabele.size(); i++)
        if(tabele[i].nume == nume)
            tabele.erase(tabele.begin() + i);
}

void MeniuPrincipal()
{
    int cursor = 0;
    int c;

    do
    {
        CLEAR();
        if(cursor == 0)  cout << ">>";
        cout << "Creare tabel nou" << endl;
        if(cursor == 1)  cout << ">>";
        cout << "Stergere tabel" << endl;
        if(cursor == 2)  cout << ">>";
        cout << "Afisare tabel" << endl;
        if(cursor == 3)  cout << ">>";
        cout << "Adaugare camp" << endl;
        if(cursor == 4)  cout << ">>";
        cout << "Stergere camp" << endl;
        if(cursor == 5)  cout << ">>";
        cout << "Adaugare obiect" << endl;
        if(cursor == 6)  cout << ">>";
        cout << "Stergere obiect" << endl;
        if(cursor == 7)  cout << ">>";
        cout << "Actualizare obiect" << endl;
        if(cursor == 8)  cout << ">>";
        cout << "Cautare obiecte" << endl;
        if(cursor == 9)  cout << ">>";
        cout << "Afisare baza de date" << endl;
        if(cursor == 10) cout << ">>";
        cout << "Iesire" << endl;

        c = getch();
        if(c == KEY_UP)
        {
            cursor--;
            if(cursor == -1)
                cursor = 10;
        }
        else if(c == KEY_DOWN)
        {
            cursor++;
            if(cursor == 11)
                cursor = 0;
        }
        else if(c == ENTER) /// verifica functionalitate cross platform
            switch(cursor)
            {
            case 0:
                CreareTabel();
                break;
            case 1:
                StergereTabel();
                break;
            case 2:
                AfisareTabel();
                break;
            case 3:
                AdaugareCamp();
                break;
            case 4:
                StergereCamp();
                break;
            case 5:
                AdaugareObiect();
                break;
            case 6:
                StergereObiect();
                break;
            case 7:
                ActualizareObiect();
                break;
            case 8:
                CautareObiect();
                break;
            case 9:
                AfisareBazaDate();
                break;
            case 10:
                return;
            }

        ScriereDate();
    }
    while(1);
}

/// Creare e functia lui Michelle, o tinem ca referinta la adaugare tabel/camp/obiect
void creare(){
    /*
    FILE *f;
    int i,j=0;
    f=fopen("asd.txt","w");
    printf("introdu cate tabele doresti : ");
    scanf("%d",&n);
    while(n!=0)
    {
        j++;
        fprintf(f,"Tabel %d\n",j);
        printf("cate campuri doresti sa ai:");
        scanf("%d",&m);
        printf("Ce campuri doriti sa intoduceti: ");
        for(i=1; i<=m; i++)
        {
            fflush(stdin);
            gets(a[0].sub[i].nume_camp);
            fprintf(f,"%s;",a[0].sub[i].nume_camp);
        }
        fprintf(f,"\n");
        printf("Cate obiecte doriti sa intoduceti: ");
        scanf("%d",&z);
        for(int k=1; k<=z; k++)
        {
            printf("\nPentru obiectul %d:",k);
            for(i=1; i<=m; i++)
            {

                printf("\nIntrodu pentru campul %d:",i);
                fflush(stdin);
                gets(a[k].sub[i].camp);
                fprintf(f,"%s;",a[k].sub[i].camp);
            }
            fprintf(f,"\n");
        }
        fprintf(f,"\n");
        n--;
    }
    fclose(f);
    */
}

int main()
{
    CitireDate();
    MeniuPrincipal();
}
