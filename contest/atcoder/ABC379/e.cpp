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

vector<int> add(vector<int> &A,vector<int> &B)
{//C=A+B,满足A>=0,B>=0
    if(A.size()<B.size()) return add(B,A);
    
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++)
    {
        t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    
    if(t) C.push_back(t);
    return C;
}

void Solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string t = s.substr(i,j-i+1);
            

        }
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
