#include <iostream>
using namespace std;
const int size_arr = 8;
int arr[size_arr][size_arr]{};
bool f = false;
int comb = 0;

void show(){
	for (int i = 0; i < size_arr; i++)
	{
		for (int j = 0; j < size_arr; j++)
			cout << (arr[i][j] ? "Ферзь " : "Пусто ");
		cout << endl;
	}
}

bool check(int row, int col){
	// проверка столбца
	for (int i = 0; i < row; i++)
		if (arr[i][col])
			return false;
	// проверка главной диагонали
	for (int i = 1; row - i >= 0 && col - i >= 0; i++)
		if (arr[row - i][col - i])
			return false;
	// проверка побочной диагонали
	for (int i = 1; row - i >= 0 && col + i < size_arr; i++)
		if (arr[row - i][col + i])
			return false;
	return true;
}

void game(int row){
	// условие выхода из рекурсии
	if (row == size_arr){
		f = true;
		cout << endl << "Result: " << endl;
		show();
		cout << endl;
		return;
	}
	if(!f)
	{
	// если индекс строки находится в пределах поля
	for (int col = 0; col < size_arr; col++)
		// проверяется каждая клетка строки
		if (check(row, col)){
			// если в клетку возможно поставить ферзя, то
			// эта клетка отмечается как 1
			arr[row][col] = 1;
			if(!f) {cout << ++comb << ")" << endl; show(); cout << endl;}
			
			// рекурсивный переход на следующую строку
			game(row + 1);

			// после выхода из рекурсии клетка принимает
			// значение 0, чтобы найти все решения задачи
			arr[row][col] = 0;
		}
	}
}

int main(){setlocale(LC_ALL,".65001"); game(0); return 0;}