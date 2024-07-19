#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;     // 地图长度
int mx, my;   // 我方无人机位置
int miny = 1e9; // 最后面的敌人的y坐标,默认无穷
char MAP[10005][10];
bool vis[10005][30];
// 敌方无人机视野填充相对位置
int fill_op[14][2] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {2, -2}, {2, -1}, {2, 0}, {2, 1}, {2, 2}};

void fill(int x, int y){
    for (int i = 0; i < 14; i++){
        int tx = x + fill_op[i][1], ty = y + fill_op[i][0];
        if (tx >= 0 && tx < 10 && ty >= 0 && ty < n){
            MAP[ty][tx] = '#';
        }
    }
 }
bool yes = 0;
int op[3][2] = {{-1, -1}, {-2, 0}, {-1, 1}};

void dfs(int x, int y){
    if (y <= miny) yes = 1;
    if (yes) return;
    vis[y][x] = 1;
    for (int i = 0; i < 3; i++){
        int tx = x + op[i][1], ty = y + op[i][0];
        if (tx >= 0 && tx < 10 && ty >= 0 && ty < n && vis[ty][tx] == 0 && MAP[ty][tx] == '.'){
            dfs(tx, ty);
        }
    }
}
 // 无人机 DFS
int main(){
    cin >> n;
    char x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cin >> x;
            if (x == '.' && MAP[i][j] == '#') continue;
            else if (x == '@') fill(j, i), miny = min(i, miny);
            else if (x == '&') mx = j, my = i, MAP[i][j] = x;
            else MAP[i][j] = x;
        }
    }
    dfs(mx, my);
    if (yes) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
 }

