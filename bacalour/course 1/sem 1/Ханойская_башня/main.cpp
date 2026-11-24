#include <iostream>
using namespace std;

void han(int n, int start, int point, int temp){
	if (n <= 0)
		return;
	// Перекладывается n - 1 дисков на свободный стержень
	han(n - 1, start, temp, point);
	// Перекладывается n-й диск на нужный стержень
	cout << start << " => " << point << endl;
	// Перекладывается n - 1 дисков на нужный стержень
	han(n - 1, temp, point, start);
}

int main(){
	int n;
	cout << "Enter the number of disks: "; cin >> n;
	han(n, 1, 3, 2); // n - k, 1 - start, 3 - where, 2 - temp
	return 0;
}