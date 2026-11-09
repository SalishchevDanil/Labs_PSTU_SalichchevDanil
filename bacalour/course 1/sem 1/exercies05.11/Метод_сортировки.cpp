#include <iostream>
using namespace std;
int main(){
    int n; cin >> n; bool f;
    int* m = new int[n]();
    for(int i = 0; i < n; ++i) cin >> m[i];

    for(int i = 1; i < n; ++i){
        f = false;
        for(int j = 0; j <i && !f; ++j){
            if(m[j] > m[i]){
                int temp = m[i];
                for(int k = i; k > j; --k) m[k] = m[k-1];
                m[j] = temp;
                f = true;
            }
            if(f) break;
        }
    }
    for(int i = 0; i < n; ++i) cout << m[i] << " ";
    return 0;
}