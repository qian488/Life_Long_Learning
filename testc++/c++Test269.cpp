#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
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
const int N=1e6+10;


void Solve()
{
    string s;
    string ans;
    while (cin>>s)
    {
        if (s=="-o")
        {
            cin >> ans;
            cout << ans << endl;
            break;
        }
        
    }
    
    /*
    string t;
    cin.clear();
    getline(cin, t);
    string s="";
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i]=='-'&&t[i+1]=='o')
        {
            i++;
            while (i<t.length())
            {
                i++;
                if (t[i]!=' ')
                    break;
            }
            i--;
            while(i<t.length())
            {
                i++;
                if (t[i]!=' ')
                {
                    s += t[i];
                }
                else break;
            }
            break;
        }
    }

    cout << s << endl;
    */
}

int main()
{
    ios 
    Solve();
    //莞工天梯赛预选赛_D.命令行是yyds	
    //耻辱的一题
    return 0;
}