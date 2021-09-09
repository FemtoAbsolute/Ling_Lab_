#include <iostream>
#include <fstream>
#include <string>
#include "Interface.h"
#include "TextProcessing.h"
#include "FileProcessing.h"

using namespace std;

void FindConsecutiveDigits(string text) 
{
    system("cls");
    bool currentDigitsFlag(false);
    auto count(0u), currentCount(count);
    string digits(""), currentDigits(digits);
    for (const auto& currentSymbol : text)
    {
        if (isdigit(currentSymbol))
        {
            if (!currentDigitsFlag) {
                currentCount = 0u;
                currentDigits = ""; 
            }
            currentDigits += currentSymbol;
            ++currentCount;
            currentDigitsFlag = true;
        }
        if (currentCount > count)
            count = currentCount;
        if (currentDigits > digits)
            digits = currentDigits;
        if (!isdigit(currentSymbol))
            currentDigitsFlag = false;
        
    }
    if (LangCheck())
    {
        cout << "Ваш текст: " << text << endl;
        cout << "Количество цифр, идущих подряд: " << count << endl;
    }
    else
    {
        cout << "Your text: " << text << endl;
        cout << "The number of consecutive digits: " << count << endl;
    }
    SaveFile(text, count, digits);
}


