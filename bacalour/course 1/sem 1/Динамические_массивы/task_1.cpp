#include <iostream>
using namespace std;
int main(){
    int* n = new int; cin >> *n;
    int* m = new int[*n];
    for(int i = 0; i < *n; ++i) cin >> m[i];
    for(int i = 0; i < *n; ++i){
        if(m[i] % 2 == 0){
            if(i == 0 || i == *n-1) m[i] = 0;
            else m[i] = m[i-1] + m[i+1];
        }
    }
    for(int i = 0; i < *n; ++i) cout << m[i] << " ";
    delete m; delete n;
    m = nullptr;
    return 0;
}