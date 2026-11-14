// Програма рекурсивним способом вилучає всі пробіли, які розташовані
// між словом та наступним за ним знаком пунктуації.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Рекурсивна перевірка, чи є символ знаком пунктуації
bool IsPunct(char c, const char* punct, int idx = 0)
{
    if (punct[idx] == '\0')
        return false;
    if (punct[idx] == c)
        return true;
    return IsPunct(c, punct, idx + 1);
}

// Рекурсивний пошук кінця групи пробілів
int SkipSpaces(const char* str, int i)
{
    if (str[i] == ' ')
        return SkipSpaces(str, i + 1);
    return i;
}

// Рекурсивне копіювання пробілів, які потрібно залишити
void CopySpaces(char* dest, int& j, int count)
{
    if (count <= 0)
        return;
    dest[j++] = ' ';
    CopySpaces(dest, j, count - 1);
}

// Основна рекурсивна функція опрацювання рядка
char* RemoveSpaces(char* dest, const char* str, int i = 0, int j = 0)
{
    const char punct[] = ".,!?;:-()\"'";
    if (str[i] == '\0')
    {
        dest[j] = '\0';
        return dest;
    }

    if (str[i] == ' ')
    {
        int k = SkipSpaces(str, i);
        bool afterWord = (j > 0 && dest[j - 1] != ' ' && !IsPunct(dest[j - 1], punct));
        bool beforePunct = (str[k] != '\0' && IsPunct(str[k], punct));

        if (!(afterWord && beforePunct))
            CopySpaces(dest, j, k - i);

        return RemoveSpaces(dest, str, k, j);
    }
    else
    {
        dest[j] = str[i];
        return RemoveSpaces(dest, str, i + 1, j + 1);
    }
}

int main()
{
    char str[151];
    cout << "Enter string:" << endl;
    cin.getline(str, 150);

    char dest[151];
    RemoveSpaces(dest, str);
    cout << "Modified string: " << dest << endl;

    return 0;
}