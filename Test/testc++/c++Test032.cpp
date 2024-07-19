#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_max(vector<int> num,int q)
{
    int l=0,r=num.size();
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(num[mid]<=q)
        {l=mid;}
        else
        {r=mid;}
    }
    return l;
}

int find_min(vector<int> num,int q)
{
    int l=0,r=num.size();
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(num[mid]>=q)
        {r=mid;}
        else
        {l=mid;}
    }
    return r;
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> num(n);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    sort(num.begin(),num.end());

    int l = find_max(num,k);
    int r = find_min(num,k);
    cout<<l<<" "<<r;
    
    return 0;
}