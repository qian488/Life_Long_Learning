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
        cin >> n;
        vector<string> g;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            g.push_back(s);
        }
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (g[i][j]=='1')
                {
                    cnt++;
                }
                
            }
            if (cnt==1)
            {
                flag = true;
            }
            else if (cnt>1)
            {
                break;
            }
            
        }
        reverse(g.begin(), g.end());
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (g[i][j]=='1')
                {
                    cnt++;
                }
                
            }
            if (cnt==1)
            {
                flag = true;
            }
            else if (cnt>1)
            {
                break;
            }
            
        }
        if (flag)
        {
            cout << "TRIANGLE" << endl;
        }
        else
        {
            cout << "SQUARE" << endl;
        }
        
    }
    
}

int main()
{
    ios
    solve();
    //Codeforces Round 928 (Div. 4)_B. Vlad and Shapes
    //其实可以直接判断是不是正方形就好
    //但是指定三角的更有挑战性，从学习的角度上考虑，要会判断三角
    //因为图形是标准的，所以只要上下有出现只有一个1的情况就是三角。。。
    return 0;
}