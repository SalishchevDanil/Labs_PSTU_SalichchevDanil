#include <iostream>
using namespace std;
int main(){
    int n; cin >> n; int* m = new int[n]();
    for(int i = 0; i < n; ++i) cin >> m[i];
    for(int i = 0; i < n; ++i){
        for(int j = n-1; j > i; --j){
            if(m[j-1] > m[j]){int temp = m[j]; m[j] = m[j-1]; m[j-1] = temp;}
        }
    }
    for(int i = 0; i < n; ++i) cout << m[i] << " ";
}