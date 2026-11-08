
#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");

    const int MAX = 200;
    int m[MAX], temp[MAX];
    int n, k;

    // Ввод массива
    cout << "Введите размер массива: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Некорректный размер массива";
        return 0;
    }

    cout << "Введите массив через пробел: ";
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    // Ввод начального элемента
    cout << "Введите индекс K (нумерация с 1): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Некорректный индекс K";
        return 0;
    }

    k--;

    // Вывод массива влево
    cout << "Массив влево: ";
    for (int i = 0; i < n; ++i) {
        cout << m[(k - i + n) % n] << " ";
    }
    cout << endl;

    // Вставка нулей после элементов с индексами,
    // кратными 5
    int j = 0;

    for (int i = 0; i < n; ++i) {
        temp[j++] = m[i];

        if (i % 5 == 0) {
            temp[j++] = 0;
        }
    }

    // Обновление массива
    int oldN = n;
    n = j;

    for (int i = 0; i < n; ++i) {
        m[i] = temp[i];
    }

    // Корректировка начального индекса K
    int newK = k;

    for (int i = 0; i < k; ++i) {
        if (i % 5 == 0) {
            newK++;
        }
    }

    // Вывод массива вправо
    cout << "Массив вправо: ";
    for (int i = 0; i < n; ++i) {
        cout << m[(newK + i) % n] << " ";
    }
    cout << endl;

    return 0;
}
