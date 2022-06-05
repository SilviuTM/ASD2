#include<stdio.h>
#include<string.h>
typedef struct tabel{

  struct camp
  {
  char nume_camp[200];
  char camp[200];
  }sub[100];
}tabel;
int m,n,z;
tabel a[200];
void creare()
{

    FILE *f;
    int i,j=0,l;
    f=fopen("asd.txt","w");
    printf("introdu cate tabele doresti : ");
    scanf("%d",&n);
    while(n!=0)
    {j++;
    fprintf(f,"Tabel %d\n",j);
    printf("cate campuri doresti sa ai:");
    scanf("%d",&m);
    printf("Ce campuri doriti sa intoduceti: ");
    for(i=1;i<=m;i++)
    {
        fflush(stdin);
        gets(a[0].sub[i].nume_camp);
        fprintf(f,"%s;",a[0].sub[i].nume_camp);
    }
    fprintf(f,"\n");
    printf("Cate obiecte doriti sa intoduceti: ");
    scanf("%d",&z);
    for(int k=1;k<=z;k++)
    {
        printf("\nPentru obiectul %d:",k);
        for(i=1;i<=m;i++)
    {

        printf("\nIntrodu pentru campul %d:",i);
        fflush(stdin);
        gets(a[k].sub[i].camp);
        fprintf(f,"%s;",a[k].sub[i].camp);
        }
       fprintf(f,"\n");}
       fprintf(f,"\n");
        n--;
        }
    fclose(f);
    }
int main()
{
    int op;
    do
    {
        printf("Optiune 1 pentru crearea catalogului\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:creare();break;
}}while(op!=0);
}
