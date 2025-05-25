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

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt0=0;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        if(a[i]==0) cnt0++;
    }
    if(cnt0==0){
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }

    if(a[0]==0&&a[n-1]==0){
        cout<<3<<endl;
        cout<<3<<" "<<n<<" "<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<2<<endl;
    }else if(a[0]==0){
        cout<<2<<endl;
        cout<<1<<" "<<n-1<<endl;
        cout<<1<<" "<<2<<endl;
    }else if(a[n-1]==0){
        cout<<2<<endl;
        cout<<2<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
    }else{
        cout<<2<<endl;
        cout<<2<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
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
