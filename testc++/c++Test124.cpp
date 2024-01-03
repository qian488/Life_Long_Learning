#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
//pta_dfs专场-- Saving James Bond - Easy Version
//跳鳄鱼
const int N=101;
int n,m;
struct point{
    int x, y;
};
vector<point> v;
bool vis[N];
bool canJump(point& a, point& b, int m) 
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int d = dx * dx + dy * dy;
    return d <= m * m;
}
bool dfs(int x)
{
    vis[x] = true;

    for (auto e:v)
    {
        
        if (!vis[]&&canJump(v[x],v[],m))
        {
            dfs()
        }
        
    }
    
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        point p;
        int x, y;
        cin >> x >> y;
        p.x = x + 50, p.y = y + 50;
        v.push_back(p);
    }
    cout << (dfs(0) ? "Yes" : "No") << endl;
    return 0;
}