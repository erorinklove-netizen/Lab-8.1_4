// Lab 8.1_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>

using namespace std;

// 1. Підрахунок кількості входжень "while"
int Count(const string s)
{
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find("while", pos)) != string::npos)
    {
        k++;
        pos += 5; // переходимо до пошуку за межами знайденого слова
    }
    return k;
}

// 2. Заміна "while" на "***"
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("while", pos)) != string::npos)
    {
        // заміна 5 символів ("while") на 3 символи ("***")
        s.replace(pos, 5, "***");
        pos += 3; // зміщуємось на довжину зірочок
    }
    return s;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "String contained " << Count(str) << " groups of 'while'" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}