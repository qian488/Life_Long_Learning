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
const int N=1e6+10;

int p[N],siz[N];
//p[]存储每个点的祖宗节点，size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

//返回祖宗节点
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

void Solve()
{
    int n,m;
    cin>>n>>m;
    vector<pii> g(m);
    
    //初始化，假定节点编号为0~n-1
    for(int i=0;i<n;i++){
        p[i]=i;
        siz[i]=1;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[i]={a,b};
        //合并a和b所在的集合
        int pa = find(a), pb = find(b);
        if(pa!=pb){
            if(siz[pa] > siz[pb]) swap(pa,pb);
            p[pa]=pb;
            siz[pb]+=siz[pa];
        }
    }

    vector<int> v;
    for(int i=0;i<n;i++){
        if(p[i]==i) v.push_back(siz[i]);
    }

    ll ans=0;
    for(auto e:v) ans += 1LL * e * (e - 1) / 2;
    sort(v.begin(),v.end());
    
    if(ans <= m) cout<< 1LL*v[0]*v[1] <<endl;
    else cout<< ans - m <<endl;
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
