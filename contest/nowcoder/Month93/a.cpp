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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n,a,k;
    cin>>n>>a>>k;
    int t=a+1;
    while(k--){
        if(t%7==0||t%10==7||(t/10)%10==7||(t/100)%10==7||(t/1000)%10==7){
            cout<<"p"<<" ";
        }else{
            cout<<t<<" ";
        }
        t+=n;
    }
    cout<<endl;
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