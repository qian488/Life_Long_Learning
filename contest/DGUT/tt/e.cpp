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
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int i=0,j=n-1;
    while (s[i]==t[i]) i++;
    while (s[j]==t[j]) j--;
    string tt = s.substr(i,j-i+1);
    reverse(tt.begin(),tt.end());
    s = s.substr(0,i)+tt+s.substr(j+1);
    if(s == t){
        cout<<i+1<<" "<<j+1<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
