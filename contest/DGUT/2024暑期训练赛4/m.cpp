#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"

using namespace std;

const int N = 25;
int n, sum = 0;
int a[N],b[N];
bool vis[N][N]={0};
vector<int>res;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x,int y) {
    a[x]--, b[y]--;
    res.push_back(x + y * n);
    vis[y][x] = 1;
    if (res.size() == sum && res[sum - 1] == n * n - 1){
        for (auto x:res) cout<<x<<" ";
        return;
    }
    for (int i=0;i<4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && vis[ny][nx] == 0 && a[nx] && b[ny]){
            dfs(nx, ny);
            if (res.size() == sum) return;
        }
    }
    // 回溯
    a[x]++, b[y]++;
    res.pop_back();
    vis[y][x] = 0;
}
int main()
{
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    dfs(0,0);
    return 0;
}