#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//跳石头
bool check(vector<int> v,int mid,int M)
{
    int y=0,j=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]-j<mid)
        {
            y++;
        }
        else
        {
            j=v[i];
        }
    }
    return y<=M;
}

int main()
{
    long long L,N,M;
    cin>>L>>N>>M;
    vector<int> v(N);
    for(int i = 0;i<N;i++)
    {
        cin>>v[i];
    }
    v.push_back(L);
    int l=0,r=L+1;
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(check(v,mid,M))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l;
    return 0;
}