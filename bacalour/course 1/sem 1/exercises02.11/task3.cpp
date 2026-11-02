#include <iostream>
using namespace std;
int main()
{
    int n,z,p;
    cin>>n;
    z=1;
    p=n/2;
    for(int i=1; i<=(n+1)/2;++i)
    {
        for (int j=1; j<=p;++j)
        {
            cout<<" ";
        }
        p=p-1;
        for(int j=1; j<=z;j++)
        {
            cout<<"*";
        }
        z+=2;
        cout<<endl;
    }
    return 0;
}