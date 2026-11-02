#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL,".UTF-8");
    int a,b,n;
    bool f=true;
    cin>>n;
    cin>>a;
    if (a!=0)
    {
        cin>>b;
        f=(a<b)&&(f);
        while ((a!=b)&&(f==true)&&(b!=0))
        {
            if (f)
            {
                a=b;
                cin>>b;
            }
        }
        if (f) {cout<<"всё нормально";}
        else {cout<<"условие не выполнилось";}

    }
    else {cout<<"Элементы в последовательности отсутствуют";}
    return 0;
}