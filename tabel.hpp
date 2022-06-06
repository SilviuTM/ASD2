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