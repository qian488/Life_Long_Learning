#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//为什么还是tle
bool check(vector<int> vm,int mid,int s)
{
    int y = 1e9+1;
    for (int i = 0; i < vm.size();i++)
    {
        y = min(y, abs(vm[i] - s));
    }

    return y >= mid;
}
long long sum=0;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> vm(m);
    for(int i=0;i<m;i++)
    {
        cin>>vm[i];
    }
    
    sort(vm.begin(),vm.end());
    while(n--)
    {
        int s;
        cin >> s;
        int l=-1,r=1e9+1;
        while(l+1<r)
        {
            int mid = l+r>>1;
            if(check(vm,mid,s))
            {
                l=mid;
            }
            else
            {
                r=mid;
            }

        }
        sum += l;
    }
    cout<<sum;
    return 0;
}