#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n=32;
    int a[n];
    int rank = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=a[0]) rank++;
    }
    if(rank==32){
        cout<<1<<endl;
    }else if(rank>=28){
        cout<<2<<endl;
    }else if(rank>=14){
        cout<<4<<endl;
    }else if(rank>=7){
        cout<<8<<endl;
    }else if(rank>=3){
        cout<<16<<endl;
    }else{
        cout<<32<<endl;
    }
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}
