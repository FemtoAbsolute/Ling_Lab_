#include <iostream>
#include <fstream>
#include "Interface.h"
#include "InterfaceInteraction.h"

using namespace std;

void MainMenu() {
	if (LangCheck())
	{
		cout << "--------------------------------------------\n";
		cout << "--------------����� ����������--------------\n";
		cout << "-------��� ����������� ������� �����--------\n";
		cout << "-------������ ���� � ������� �������--------\n";
		cout << "------------------\"Enter\"-------------------\n";
		cout << "--------------------------------------------\n";
		cout << "--------------------����--------------------\n";
		cout << "------------   1. � ���������   ------------\n";
		cout << "--------   2. ������ ���� ������   ---------\n";
		cout << "-----   3. �������� ������ �� �����   ------\n";
		cout << "------------   4. ����� �����   ------------\n";
		cout << "---------------   5. �����   ---------------\n";
		cout << "--------------------------------------------\n\n";
		cout << "��� ����� : ";
	}
	else
	{
		cout << "--------------------------------------------\n";
		cout << "-------------------Welcome------------------\n";
		cout << "----------------To continue,----------------\n";
		cout << "-----select the number of the menu item-----\n";
		cout << "-------------and press \"Enter\"--------------\n";
		cout << "--------------------------------------------\n";
		cout << "--------------------Menu--------------------\n";
		cout << "---------------   1. About   ---------------\n";
		cout << "-----------   2. Manual input   ------------\n";
		cout << "---------   3. Upload from file   ----------\n";
		cout << "----------   4. Change language   ----------\n";
		cout << "---------------   5. Exit   ----------------\n";
		cout << "--------------------------------------------\n\n";
		cout << "Your choice : ";
	}
}

void AboutMenu() {
	if (LangCheck()) {
		cout << "--------------------------------------------\n";
		cout << "������ ��������� ������������� ��� ������\n";
		cout << "����������� ���������� ���� � ������, \n";
		cout << "������ ������\n";
		cout << "--------------------------------------------\n";
	}
	else
	{
		cout << "--------------------------------------------\n";
		cout << "The program is designed to search \n";
		cout << "for the largest number of consecutive \n";
		cout << "digits in the text\n";
		cout << "--------------------------------------------\n";
	}
}

bool LangCheck() {
	string path = "settings.ini";
	ifstream fin(path);
	if (!fin.is_open())
	{
		ofstream fout(path);
		fout << "ENG";
		fout.close();
		return false;
	}
	else
	{
		string lang;
		fin >> lang;
		if (lang == "RUS")
			return true;
		else if (lang == "ENG")
			return false;
		else {
			ofstream fout(path);
			fout << "ENG";
			fout.close();
			return false;
		}
	}
}

int Check(int userChoice) {


	while (cin.fail()) {
		if (userChoice <= 0) {
			if(LangCheck())
				cout << "������������ ����. ���������� ��� ���." << endl;
			else
				cout << "Incorrect input. Try again." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			userChoice = 0;
			cin >> userChoice;
		}
	}
	return (userChoice);
}

bool MenuOrExit() {
	int userChoice;
	if (LangCheck())
	{
		cout << endl << "��������� � ���� ��� ����� �� ���������?" << endl;
		cout << "1. ��������� � ����" << endl;
		cout << "2. ����� �� ���������" << endl;
	}
	else
	{
		cout << endl << "Back to menu or exit?" << endl;
		cout << "1. Menu" << endl;
		cout << "2. Exit" << endl;
	}
	cin >> userChoice;
	userChoice = Check(userChoice);
	if (userChoice == 1)
		return false;
	else if (userChoice == 2)
		return true;
	else {
		if (LangCheck()) {
			cout << "������������ ����. ���������� ��� ���" << endl;
			MenuOrExit();
		}
		else
			cout << "Incorrect input. Try again" << endl;
			MenuOrExit();
	}
}