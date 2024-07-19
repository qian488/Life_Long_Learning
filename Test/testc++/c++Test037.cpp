#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(vector<int> v,int mid,int M)
{
    int y=0,j=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]+j<=mid)
        {
            j += v[i];
        }
        else
        {
            j = v[i];
            y++;
        }
        
    }

    return y>=M;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> v(N);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l=-1,r=1e9+1;
    while(l+1<r)
    {
        int mid = l + r >>1;
        if(check(v,mid,M))
        {l=mid;}
        else
        {r=mid;}
    }
    cout<<l;
    return 0;
}