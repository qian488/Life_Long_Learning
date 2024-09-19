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

int p[N],sz[N];//存储每个点的祖宗节点

//返回x的祖宗节点
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

void init(int n){
    //初始化，假定节点编号是0~n
    for(int i=0;i<=n;i++){ 
        p[i]=i;
        sz[i]=1;
    }
}

void merge(int a,int b){
    int pa=find(a),pb=find(b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) {
            swap(pa, pb);
        }
        p[pb] = pa;
        sz[pa] += sz[pb];
    }
}

void Solve(){
    int n;
    cin>>n;
    init(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        l--;
        merge(l,r);
    }
    cout<<((sz[find(0)]==n+1)?1:0)<<endl;
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
