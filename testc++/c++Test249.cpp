#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N = 1e6 + 10;

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin>>n;
        string s;
        cin >> s;
        int cnt[5];
        memset(cnt, 0, sizeof cnt);
        int ans = 0;
        for (int i = 1; i < n-1;i++) 
        {
            if(s[i]=='a'&&s[i-1]=='m'&&s[i+1]=='p') 
            {
                ans++;
                i++;
            }
            if(s[i]=='i'&&s[i-1]=='p'&&s[i+1]=='e') 
            {
                ans++;
                i++;
            }
            /*
            if(s[i]=='m') cnt[0]++;
            else if(s[i]=='a') cnt[1]++;
            else if(s[i]=='p') cnt[2]++;
            else if(s[i]=='i') cnt[3]++;
            else if(s[i]=='e') cnt[4]++;
            */
        }
        for (int i = 2; i < n-2;i++)
        {
            if(s[i]=='p'&&s[i-1]=='a'&&s[i+1]=='i'&&s[i+2]=='e'&&s[i-2]=='m') 
            {
                ans--;
                i += 2;
            }
        }
        /*
        int ans = INF;
        int a = min(cnt[0], cnt[1]);
        int b = min(cnt[3], cnt[4]);
        ans = min(ans, a + b);
        ans = min(ans, cnt[2]);
        if(a<b)
            ans = a;
        else
            ans = b;
            */
        /*
        if(cnt[2]>=a+b) ans = a + b;
        else ans = cnt[2];
        */
        cout << ans << endl;
    }
    
}

int main()
{
    ios
    solve();
    //Codeforces Round 933 (Div. 3)_C.Rudolf and the Ugly String
    //md,都错题意了。
    //无语了。。。
    //气死了
    return 0;
}