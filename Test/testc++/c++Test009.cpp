#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,min=0;
    double s;
    cin>>a>>b>>c;
    if(a<=b&&a<=c)
    {
        min=a;
    }
    else if(b<=a&&b<=c)
    {
        min=b;
    }
    else if(c<=a&&c<=b)
    {
        min=c;
    }
    if(min==a)
    {
        s=sqrt(1-pow(((b*b+c*c-a*a)*1.0)/(2*b*c),2));
    }
    else if(min==b)
    {
        s=sqrt(1-pow(((a*a+c*c-b*b)*1.0)/(2*a*c),2));
    }
    else if(min==c)
    {
        s=sqrt(1-pow(((b*b+a*a-c*c)*1.0)/(2*b*a),2));
    }
    cout<<s;
    return 0;
}