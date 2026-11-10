// Lab_08_1_char.cpp
// Фащевський Богдан
// Лабораторна робота № 8.1
// Варіант 28
// Пошук та заміна символів у літерному рядку

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool Include(const char* s)
{
    const char* cs = "while"; // Ініціалізуємо рядок-шаблон із символами слова "while"
    bool r = true; // Створюємо прапорець результату (початково true — припускаємо, що всі букви присутні)
    for (int i = 0; cs[i] != '\0'; i++) // Цикл по черзі перебирає кожен символ слова "while" до нуль-термінатора
    {
        r = r && (strchr(s, cs[i]) != NULL); // Перевіряємо наявність символу cs[i] у рядку s через strchr та акумулюємо результат через логічне "І"
    }
    return r; // Повертаємо true, якщо знайдено всі букви, або false, якщо бодай однієї немає
}

char* Change(char* s)
{
    char* t = new char[strlen(s) + 1]; // Виділяємо динамічну пам'ять під новий рядок t відповідного розміру
    char* p; // Оголошуємо вказівник p для фіксації адреси знайденого підрядка "while"
    int pos1 = 0, pos2 = 0; // Оголошуємо позиції: pos1 — початок неопрацьованого фрагмента s, pos2 — позиція одразу після "while"
    *t = '\0'; // Записуємо нуль-термінатор на початок t, ініціалізуючи порожній C-рядок для коректної роботи strcat/strncat
    while ((p = strstr(s + pos1, "while")) != NULL) // Цикл шукає підрядок "while", починаючи з s + pos1, поки не знайде всі входження, тобто «Шукай слово "while", починаючи з позиції pos1. Запиши знайдену адресу в p. І поки ми щось знаходимо (поки p не NULL) — продовжуй виконувати тіло циклу».
    {
        pos2 = static_cast<int>(p - s) + 5; // Обчислюємо індекс pos2 як позицію у вихідному рядку s одразу за знайденим словом "while" (довжина 5)
        strncat(t, s + pos1, pos2 - pos1 - 5); // Копіюємо в t символи з s від pos1 до початку знайденого слова "while"
        strcat(t, "**"); // Додаємо в кінець t дві зірочки "**" замість слова "while"
        pos1 = pos2; // Зміщуємо pos1 за знайдене слово "while" для продовження пошуку
    }
    strcat(t, s + pos1); // Додаємо в t залишок вихідного рядка s, що залишився після останнього знайденого слова "while"
    strcpy(s, t); // Копіюємо сформований результат із тимчасового буфера t назад у вихідну змінну s
    return t; // Повертаємо вказівник на модифікований рядок t
}

#ifndef UNIT_TESTING
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    if (Include(str))
        cout << "String contains all letters from 'while'" << endl;
    else
        cout << "String DOES NOT contain all letters from 'while'" << endl;
    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
#endif