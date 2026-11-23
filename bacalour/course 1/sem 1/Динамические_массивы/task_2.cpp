#include <iostream>
using namespace std;
int main(){
    int* n = new int; cin >> *n;
    int* m = new int[*n];
    for(int i = 0; i < *n; ++i){
        m[i] = rand()%100 + 1;
        cout << m[i] << " ";
    }
    int* sum = new int; *sum = 0;
    for(int i = 0; i < *n; ++i) *sum += m[i];
    cout << endl << *sum;
    delete sum; delete n; delete m;
    return 0;
}