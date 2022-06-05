#include<iostream>
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

void CreareTabel(/**/){}
void StergereTabel(/**/){}
void AfisareTabel(/**/){}
void AdaugareCamp(/**/){}
void StergereCamp(/**/){}
void AdaugareObiect(/**/){}
void StergereObiect(/**/){}
void ActualizareObiect(/**/){}
void CautareObiect(/**/){}
void AfisareBazaDate(/**/){}

void CitireDate(){}
void ScriereDate(){}

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
