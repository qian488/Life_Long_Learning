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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;
#define P pair<char,int>

void Solve(){
    string s; cin>>s;
    int n=s.size();
    string t=s+s;
    vector<int>tt(n,-1);
    stack<P>sta;
    deque<int>ql,qr;
 
    const ll mod1=998244353,mod2=1e9+7;
    vector<ll>hs(2*n),ex(2*n,1);
    for(int i=1;i<=2*n;i++)
    {
        ex[i]=ex[i-1]*mod1%mod2;
        hs[i]=(hs[i-1]*mod1+t[i-1])%mod2;
    }
    auto geths=[&](int l,int r)->ll{
        return (hs[r+1]-hs[l]*ex[r-l+1]%mod2+mod2)%mod2;
    };
    auto check=[&](int s1,int s2)->bool{
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+r>>1;
            if(geths(s1,s1+mid-1)==geths(s2,s2+mid-1))l=mid+1;
            else r=mid;
        }
        return t[s1+l-1]>t[s2+l-1];
    };
         
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')sta.push({s[i],i});
        else if(sta.size()&&sta.top().first=='(')tt[sta.top().second]=i,sta.pop();
        else sta.push({')',i});
    }
    while(sta.size())
    {
        if(sta.top().first=='(')ql.push_front(sta.top().second);
        else qr.push_front(sta.top().second);
        sta.pop();
    }
    int ansl=ql.size(),st=0,ansr=qr.size();
 
    for(int i=0;i<n;i++)
    {
        int j=i;
        if(s[j]=='(')
        {
            if(tt[j]>=0)qr.push_front(tt[j]),ql.push_back(j),tt[j]=-1;
            else ql.pop_front(),ql.push_back(j);
        }
        else
        {
            if(ql.size())qr.pop_front(),tt[ql.back()]=i,ql.pop_back();
            else qr.pop_front(),qr.push_back(j);
        }
 
        if(ql.size()+qr.size()<ansl+ansr)
        {
            ansl=ql.size(),ansr=qr.size(),st=i+1;
        }
        else if(ql.size()+qr.size()==ansl+ansr&&check(st,i+1))
        {
            st=i+1;
        }
    }
         
    string ans="";
    for(int i=1;i<=ansr;i++)ans+='(';
    ans+=t.substr(st,n);
    for(int i=1;i<=ansl;i++)ans+=')';
 
    cout<<ans<<"\n";
}
int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}

/*
读入一个字符串 s。
构造一个 t = s + s 的字符串,以方便后续的子串计算。
使用栈 sta 记录左括号的位置,并用数组 tt 记录每个左括号对应的右括号的位置。
使用双端队列 ql 和 qr 分别记录未匹配的左括号和右括号的位置。
使用哈希算法计算子串的哈希值,并定义了 geths() 和 check() 两个辅助函数来进行子串比较。
遍历字符串 s,根据括号的类型(左括号或右括号)更新 ql、qr 和 tt 数组。同时记录当前最小的未匹配括号数 ansl 和 ansr。
最后构造出答案字符串 ans,将 ansr 个左括号、子串 t.substr(st, n)、以及 ansl 个右括号拼接起来。
*/