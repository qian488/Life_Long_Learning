#include<iostream>
#include<map>
using namespace std;
//取数排列
const int N = 10;
int n, m, cnt = 0;
int p[N];
bool vis[N];
map<string, int> ans;
void dfs(int x)
{
    if (x==n)
    {
        string s = "";
        for (int i = 0; i < n; i++)
        {
            //cout << p[i] ;
            s += to_string(p[i]);
        }
        cnt++;
        ans[s] = cnt;
        //cout << s << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            p[x] = i;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
        
    }
    
    
}
int main()
{
    cin >> n >> m;
    dfs(0);
    for(auto e:ans)
    {
        //cout << e.first <<" "<< e.second << endl;
        if (e.second==m)
        {
            cout << e.first << endl;
        }
        
    }
    
    return 0;
}