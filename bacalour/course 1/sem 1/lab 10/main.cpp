#include <iostream>
#include <string>
using namespace std;

// Функция перевода русской буквы в нижний регистр
string lowerLetter(string s) {
    string upper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string lower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    for (int i = 0; i < upper.size(); i += 2) {
        if (s == upper.substr(i, 2))
            return lower.substr(i, 2);
    }

    return s;
}

int main() {
    setlocale(LC_ALL, ".65001");

    cout << "Задача 20" << endl;

    int n, k = 0;

    cout << "Введите количество элементов массива: ";
    cin >> n;
    cin.ignore();

    string* m = new string[n]();

    // Ввод массива
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " строка: ";
        getline(cin, m[i]);
    }

    // Проверка строк
    for (int i = 0; i < n; i++) {
        if (!m[i].empty()) {
            string first, last;

            // Получение первой и последней букв
            first = m[i].substr(0, 2);
            last = m[i].substr(m[i].size() - 2, 2);

            first = lowerLetter(first);
            last = lowerLetter(last);

            // Удаление подходящих строк
            if (first == last) {
                m[i].clear();
                k++;
            }
        }
    }

    // Создание нового массива
    string* nm = new string[n - k]();

    for (int i = 0, j = 0; i < n; i++) {
        if (!m[i].empty()) {
            nm[j] = m[i];
            j++;
        }
    }

    delete[] m;
    m = nm;
    nm = nullptr;

    // Вывод результата
    cout << endl << "Массив после удаления:" << endl;

    for (int i = 0; i < n - k; i++)
        cout << m[i] << endl;

    delete[] m;
    m = nullptr;

    return 0;
}