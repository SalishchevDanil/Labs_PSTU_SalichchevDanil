#include <iostream>
#include <clocale>
using namespace std;

// Функция ввода матрицы
void inp(int** a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        cout << "Введите " << i + 1 << " строку: ";
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
}

// Функция поиска минимального из неповторяющихся
int findminx(int** a, int n, int m) {
    int minx = 0;
    bool f = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cur = a[i][j];
            int cnt = 0;

            // Считаем, сколько раз cur встречается в матрице
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < m; ++c) {
                    if (a[r][c] == cur) {
                        cnt++;
                    }
                }
            }

            // Если элемент уникален
            if (cnt == 1) {
                if (!f) {
                    minx = cur;
                    f = true;
                } else if (cur < minx) {
                    minx = cur;
                }
            }
        }
    }

    if (!f) return -9999; // Если уникальных нет
    return minx;
}

int main() {
    setlocale(LC_ALL, ".65001");
    int n, m;

    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[m];
    }

    inp(a, n, m);
    int res = findminx(a, n, m);

    if (res == -9999) {
        cout << "Нет неповторяющихся элементов." << endl;
    } else {
        cout << "Минимальный из неповторяющихся: " << res << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}