#include <iostream>
#include <string>    // для работы со строками
#include <clocale>
#include <cctype>    // для isalpha, isalnum

using namespace std;

struct mass { bool f = true; string s; }; // структура для слов

int main() {
    setlocale(LC_ALL, ".65001");
    string s;
    
    cout << "Введите строку: ";
    getline(cin, s); // ввод строки с пробелами

    // По заданию в конце стоит точка, отрезаем её, чтобы она не мешала
    if (!s.empty() && s.back() == '.') {
        s.pop_back();
    }

    int n = s.length();
    int j = 0;
    mass* m = new mass[100](); // массив для слов

    // Выделяем слова из строки по пробелу
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            m[j].s += s[i];
        } else {
            if (!m[j].s.empty()) ++j; // если пробелов несколько подряд
        }
    }

    // Проверяем каждое слово на то, является ли оно идентификатором
    for (int i = 0; i <= j; ++i) {
        if (m[i].s.empty()) continue; // пропускаем пустые

        // 1. Первый символ должен быть буквой или знаком подчеркивания
        if (!isalpha(m[i].s[0]) && m[i].s[0] != '_') {
            m[i].f = false;
        } else {
            // 2. Остальные символы: буквы, цифры или подчеркивание
            for (int k = 1; k < m[i].s.length(); ++k) {
                char c = m[i].s[k];
                if (!isalnum(c) && c != '_') {
                    m[i].f = false;
                    break;
                }
            }
        }
    }

    // Вывод оставшихся слов
    cout << "Строка после обработки: ";
    bool first = true;
    for (int i = 0; i <= j; ++i) {
        if (m[i].f && !m[i].s.empty()) {
            if (!first) cout << " ";
            cout << m[i].s;
            first = false;
        }
    }
    cout << endl;

    return 0;
}