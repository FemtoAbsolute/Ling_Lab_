#include <iostream>
#include <fstream>
#include <string>
#include "TextProcessing.h"
#include "Interface.h"
#include "FileProcessing.h"

using namespace std;

enum userChoice { About = 1, Manual, File, Lang, Exit, Yes = 1, No};

int Menu() 
{

int userChoice, menuOption;
while (true)
	{
	
		MainMenu();
		
		userChoice = menuOption = 0;

		cin >> userChoice;
		menuOption = Check(userChoice);

		switch (menuOption) {
			case About: {
				system("cls");
				AboutMenu();
				if (MenuOrExit())
					return(0);
				system("cls");
				break;
			}

			case Manual: {
				string text;
				if (LangCheck())
					cout << "¬ведите текст и нажмите кнопку \"Enter\": ";
				else
					cout << "Enter the text and press \"Enter\": ";
				string wc;
				getline(cin >> wc, text);
				FindConsecutiveDigits(wc + text);
				cin.get();
				break;
			}
		
			case File: {
				string fileName;
				if(LangCheck())
					cout << "¬ведите полное им€ файла: " << endl;
				else
					cout << "Enter name of file: " << endl;
				cin >> fileName;
				UploadFromFile(fileName);
				break;
			}

					 
			case Lang: {
				string path = "settings.ini";
				ifstream fin(path);
				if (fin.is_open())
				{
					if (LangCheck()) {
						ofstream fout(path);
						fout << "ENG";
						fout.close();
					}
					else {
						ofstream fout(path);
						fout << "RUS";
						fout.close();
					}
				}
				system("cls");
				break;
			}

			case Exit:
				return 0;
		}

	}

}
