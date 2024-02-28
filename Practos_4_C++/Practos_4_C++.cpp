#include <iostream>
#include <Windows.h>
#include <random>

using namespace std;

void removeVowels(string word, bool glasn)
{
    char gl[10] = { 'а', 'о', 'э', 'у', 'я', 'и', 'ю', 'ё' };
    for (char w_letter : word)
    {
        bool flag = true;
        for (char letter : gl)
        {
            if (glasn == true && w_letter == letter)
            {
                cout << letter;
            }
            if (glasn == false && w_letter == letter)
            {
                flag = false;
                break;
            }
        }
        if (flag && glasn == false)
        {
            cout << w_letter;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    setlocale(0, "ru");
    string s;
    do {
        cout << "\nВведите слово с которым хотите работать: ";
        cin >> s;
        cout << "\n1.Слово выводится задом наперед.\n2.Вывести слово без гласных.\n3.Вывести слово без согласных.\n4.Рандомно раскидывать буквы заданного слова.\nВведите номер действия: ";
        int sw;
        cin >> sw;
        switch (sw)
        {
        case 1:
            reverse(s.begin(), s.end());
            cout << s;
            break;
        case 2:
            removeVowels(s, false);
            break;
        case 3:
            removeVowels(s, true);
            break;
        case 4:
            random_shuffle(s.begin(), s.end());
            cout << s;
            break;
        }
    } while (s != "STOP");
}

