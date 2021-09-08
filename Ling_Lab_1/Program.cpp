#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>
#include <fstream>
#include "InterfaceInteraction.h"


using namespace std;

void CheckSettings() {
    string path = "settings.ini";
    ifstream fin(path);
    if (!fin.is_open())
    {
        ofstream fout(path);
        fout << "ENG";
        fout.close();
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RU");
    CheckSettings(); 
    Menu();
    cin.get();
	
}