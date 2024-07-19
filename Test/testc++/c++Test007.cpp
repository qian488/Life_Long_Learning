#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,h,m;
    cin>>a>>b>>c>>d;
    h=((c*60+d)-(a*60+b))/60;
    m=((c*60+d)-(a*60+b))%60;
    cout<<h<<" "<<m;
    return 0;
}