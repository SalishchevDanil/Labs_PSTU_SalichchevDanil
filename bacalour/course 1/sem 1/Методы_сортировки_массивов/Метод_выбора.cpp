#include <iostream>
using namespace std;
int main(){
    int n, k; cin >> n; int* m = new int[n]();
    for(int i = 0; i < n; ++i) cin >> m[i];
    for(int i = 0; i < n; ++i){
        int min = m[i];
        for(int j = i; j < n; ++j){
            if(m[j] <= min){min = m[j]; k = j;}
        }
        m[k] = m[i];
        m[i] = min;
    }
    for(int i = 0; i < n; ++i) cout << m[i] << " ";
    return 0;
}