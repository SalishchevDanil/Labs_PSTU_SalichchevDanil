#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL,".UTF-8");
    int n,s=0,a=1;
    cout<<"Введите n: ";
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        for (int j=i;j<=(2*i);++j)
        {
            a=a*j;
        }
        s+=a;
        a=1;
    }
    cout<<s;
    return 0;
}