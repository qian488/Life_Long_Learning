#include<iostream>
using namespace std;
#define PI 3.14
int main()
{
    int h,r,v,s;
    cin>>h>>r;
    v=PI*h*r*r;
    s=(20000/v)+1;
    cout<<s;
    return 0;
}