#include<iostream>

using namespace std;
//kotori的设备--实数二分
const int N = 1e6 + 1;
double a[N],b[N],p;
bool check(double k,int n)
{
    double _sum=0;
    for(int i = 0;i<n;i++)
    {
        if(b[i]<k*a[i])
        {
            _sum+=k*a[i]-b[i];
        }
    }
    return _sum<p*k;
}

int main()
{
    int n;
    cin>>n>>p;
    double sum=0;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=a[i];
    }

    double l=0,r=1e10;
    while(r-l>1e-6)
    {
        double mid=(l+r)/2;
        if(check(mid,n))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }

    if(sum<=p)
    {
        cout<<"-1";
    }
    else
    {
        cout<<l;
    }
    return 0;
}