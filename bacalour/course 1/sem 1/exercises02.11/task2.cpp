#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    int n, s=0, a=1;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        for (int j=i;j<=2*i;++j)
        {
            a=a*i;
        }
        s+=a;
    }
    cout<<s;
    return 0;
}
