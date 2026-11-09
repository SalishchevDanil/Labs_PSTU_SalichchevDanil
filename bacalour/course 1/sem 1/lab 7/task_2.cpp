#include <iostream>
#include <cstdarg>
#include <clocale>
using namespace std;

bool is_treug(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void treug(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int t_cnt = 0;
    for (int i = 0; i < count / 3; ++i) {
        int a = va_arg(args, int);
        int b = va_arg(args, int);
        int c = va_arg(args, int);
        
        if (is_treug(a, b, c)) {
            t_cnt++;
        }
    }
    
    va_end(args);
    cout << "Треугольников: " << t_cnt << endl;
}

int main() {
    setlocale(LC_ALL, ".65001");
    int n;
    
    cout << "Введите количество чисел (3, 9 или 11): ";
    cin >> n;
    
    int m[20]; // запас
    cout << "Введите числа через пробел: ";
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    // Из-за особенностей функций с "..." мы обязаны явно 
    // перечислить аргументы в зависимости от их количества.
    switch(n) {
        case 3: 
            treug(3, m[0], m[1], m[2]); 
            break;
        case 9: 
            treug(9, m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]); 
            break;
        case 11: 
            treug(11, m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10]); 
            break;
        default: 
            cout << "Поддерживается только 3, 9 или 11 чисел!" << endl;
            break;
    }
    return 0;
}