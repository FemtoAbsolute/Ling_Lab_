#include <iostream>
#include <fstream>
#include <string>
#include "Interface.h"
#include "FileProcessing.h"
#include "TextProcessing.h"

enum userChoice { Yes = 1, No };

using namespace std;

void SaveFile(string text, int count, string digits) { 
    int userChoice;
    if (LangCheck())
        cout << "Нажмите '1' если вы хотите сохранить результаты обработки или клавишу '2', если хотите продолжить работу: " << endl;
    else
        cout << "Press '1' if you want to save result of processing or '2' to continue: " << endl;
    cin >> userChoice;
    userChoice = Check(userChoice);
    if (userChoice == Yes) {
        ofstream out;
        string filePath;
        if (LangCheck())
            cout << "Введите путь к файлу и его имя: " << endl;
        else
            cout << "Enter the path to the file and its name: " << endl;
        cin >> filePath;
       
        out.open(CheckFileName(filePath));
        if (LangCheck())
        {
            out << "Введенный текст: " << text << endl;
            out << "Самая длинная последовательность цифр: " << digits << endl;
            out << "Количество цифр в последовательности: " << count << endl;
            cout << "Файл сохранен" << endl;
        }
        else
        {
            out << "Entered text: " << text << endl;
            out << "The longest sequence of digits: " << digits << endl;
            out << "The number of digits in the sequence: " << count << endl;
            cout << "File saved successfully" << endl;
        }
        out.close();
        system("cls");
    }
    if (LangCheck())
        cout << "Нажмите '1' если вы хотите сохранить исходный текст или клавишу '2', если хотите продолжить работу: " << endl;
    else
        cout << "Press '1' if you want to save unprocessed text or '2' to continue: " << endl;
    cin >> userChoice;
    userChoice = Check(userChoice);
    if (userChoice == Yes) {
        ofstream out;
        string filePath;
        if (LangCheck())
            cout << "Введите путь к файлу и его имя: " << endl;
        else
            cout << "Enter the path to the file and its name: " << endl;
        cin >> filePath;
        out.open(CheckFileName(filePath));
        out << text << endl;
        cout << "Файл сохранен" << endl;
        out.close();
        system("cls");
    }
    system("cls");

}

string CheckFileName(string filePath) {
    int rewrite;
    while (ValidateName(filePath) == false) {
        if (LangCheck())
            cout << "Некорректное имя файла. Введите новое: ";
        else
            cout << "Invalid file name. Input new name: ";
        cin >> filePath;
    }
    if (ofstream(filePath, ios::out | ios::_Nocreate)) {
        if(LangCheck())
            cout << "Файл с таким именем уже существует. Выберите '1', чтобы перезаписать и '2', чтобы ввести другое имя: " << endl;
        else
            cout << "A file with this name already exists. Select '1' to overwrite and '2' to enter a different name: " << endl;
        cin >> rewrite;
        Check(rewrite);
        if (rewrite == No) {
            if (LangCheck())
                cout << "Введите новое имя файла:" << endl;
            else
                cout << "Enter new name for file:" << endl;
            cin >> filePath;
            CheckFileName(filePath);
        }
        else if (rewrite == Yes)
            return(filePath);
    }
    return (filePath);
}


bool ValidateName(string filePath) {
    string restrictedSymbols[] = { "<", ">", "/", "|", "?", "*", };
    string restrictedNames[] = { "con", "prn", "aux", "nul", "com1", "com2", "com3", "com4", "com5", "com6", "com7",
                                        "com8", "com9", "lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };
    string copyOfPath = filePath;
    for (int i = 0; i != filePath.length(); i++) {
        copyOfPath[i] = tolower(filePath[i]);
    }

    int restrictedSymbolsSize = sizeof(restrictedSymbols) / sizeof(restrictedSymbols[0]);
    int restrictedNamesSize = sizeof(restrictedNames) / sizeof(restrictedNames[0]);
    for (int i = 0; i != restrictedSymbolsSize; ++i) {
        if (string::npos != copyOfPath.find(restrictedSymbols[i]))
            return false;
    }
    for (int i = 0; i != restrictedNamesSize; ++i) {
        if (copyOfPath == restrictedNames[i])
            return false;
    }
    return true;
}

int UploadFromFile(string fileName) {
    ifstream in(fileName);
    string text(""), tempText;;
    if (in.is_open()) {
        while (in)
        {
            in >> tempText;
            text += tempText + " ";
        }
        in.close();
       FindConsecutiveDigits(text);
       return (0);
    }
    else {
        if(LangCheck())
            cout << "Невозможно открыть файл" << endl;
        else
            cout << "Can't open this file" << endl;
        if (MenuOrExit == 0)
            return(0);
    }
}