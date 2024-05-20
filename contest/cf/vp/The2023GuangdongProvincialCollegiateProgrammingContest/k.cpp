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
int n, m, k;
int dx[] = {2, 0, -2, 0};
int dy[] = {0, 2, 0, -2};

vector<vector<pii>> result;
vector<pii> path;

void fuck (vector<pii>& nums, vector<bool>& vis) {
    // 此时说明找到了一组
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (vis[i] == true) continue; // path里已经收录的元素，直接跳过
        vis[i] = true;
        path.push_back(nums[i]);
        fuck(nums, vis);
        path.pop_back();
        vis[i] = false;
    }
}

vector<vector<pii>> permute(vector<pii>& nums) {
    result.clear();
    path.clear();
    vector<bool> vis(nums.size(), false);
    fuck(nums, vis);
    return result;
}

int bfs(vector<pii>& v,vector<vector<int>> &grid){
    int ans = k;
    queue<pii> q;
    for(auto e:v){
        q.push(e);
    }
    while (!q.empty()){
        auto e = q.front();
        int x = e.first, y = e.second;
        q.pop();
        if(!grid[x][y]) continue;
        for (int i = 0; i < 4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u<1||u>n||v<1||v>m) continue;
    
            if(grid[x][y]&&grid[(u + x) / 2][(v + y) / 2]&&!grid[u][v]){
                grid[u][v] = 1;
                grid[x][y] = 0;
                grid[(u + x) / 2][(v + y) / 2] = 0;
                ans--;
                q.push({u, v});
            }
        }
    }
    return ans;
}

int ans;
void dfs(vector<vector<int>> &grid,int k){
    ans = min(ans, k);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(!grid[i][j]) continue;
            for (int l = 0; l < 4;l++){
                int x = i + dx[l], y = j + dy[l];
                if(x<1||x>n||y<1||y>m) continue;

                if(grid[i][j]&&grid[(x+i)/2][(y+j)/2]&&!grid[x][y]){
                    grid[i][j] = 0;
                    grid[(x + i) / 2][(y + j) / 2] = 0;
                    grid[x][y] = 1;
                    dfs(grid, k - 1);
                    grid[i][j] = 1;
                    grid[(x + i) / 2][(y + j) / 2] = 1;
                    grid[x][y] = 0;
                }
            }
        }
    }
}

void Solve()
{ // bfs模拟 ? 差一个全排列
    cin >> n >> m >> k;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    vector<pii> v;
    for (int i = 0; i < k;i++){
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
        v.push_back({x, y});
    }
    ans = k;
    dfs(grid, k);
    /*
    sort(v.begin(), v.end());
    vector<vector<pii>> result = permute(v);
    // 构造v的全排列vv  为什么不行。。。
    for(auto vv:result){
        
        for(auto e:vv)
            cout << e.first << "-" << e.second << " ";
        cout << endl;
        
        ans = min(ans, bfs(vv,grid));
    }
    */
    cout << ans << endl;
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
