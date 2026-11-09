#include <iostream>
#include <string>
#include <clocale>
using namespace std;

// 1. Для массива: считаем четные элементы
int count(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) c++;
    }
    return c;
}

// 2. Для строки: считаем слова на букву 'а'
int count(string s) {
    int c = 0;
    bool word = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ' && !word) {
            word = true; // началось новое слово
            
            // 1. Проверка на латинскую 'a' или 'A'
            if (s[i] == 'a' || s[i] == 'A') {
                c++;
            }
            // 2. Проверка на русскую 'а'/'А' для Windows-1251 (1 байт)
            else if ((unsigned char)s[i] == 0xE0 || (unsigned char)s[i] == 0xC0) {
                c++;
            }
            // 3. Проверка на русскую 'а'/'А' для UTF-8 (2 байта: 0xD0 0xB0 и 0xD0 0x90)
            else if (i + 1 < s.length() && (unsigned char)s[i] == 0xD0) {
                if ((unsigned char)s[i+1] == 0xB0 || (unsigned char)s[i+1] == 0x90) {
                    c++;
                }
            }
        } else if (s[i] == ' ') {
            word = false; // слово закончилось
        }
    }
    return c;
}

int main() {
    setlocale(LC_ALL, ".65001");
    
    // Ввод массива
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int arr[100]; 
    cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    cout << "Четных элементов в массиве: " << count(arr, n) << endl;
    
    // Ввод строки
    cin.ignore(); 
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    
    cout << "Слов на 'а' в строке: " << count(s) << endl;
    
    return 0;
}