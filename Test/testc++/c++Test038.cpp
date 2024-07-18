#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
//银行贷款
using namespace std;
unsigned long long w0,w,m;
double t = 0;
int main()
{
    
    cin>>w0>>w>>m;
    double l=0,r=1e6+1;
    while(r-l>=1e-6)
    {
        double mid=(l+r)/2;
        
        for(int i=1;i<=m;i++)
        {
            t += 1.0 / pow((mid), i);
        }
        if(t>=(w0*1.0/w))
        {l=mid;}
        else
        {r=mid;}
    }
    cout << t <<" "<<(w0*1.0/w)<< " " <<1000000000*1.0/2147483647<< endl;
    cout<<fixed<<setprecision(1)<<l*100;
    return 0;
}