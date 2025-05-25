#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int INF = 0x3f3f3f3f;
const int dx[4] = {-1, 1, 0, 0}; 
const int dy[4] = {0, 0, -1, 1};

void solve() {
    int H, W, A, B, C, D;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];
    cin >> A >> B >> C >> D;
    --A; --B; --C; --D; 

    vector<vector<int>> dist(H, vector<int>(W, INF));
    deque<pair<int,int>> dq;
    dist[A][B] = 0;
    dq.push_front({A, B});

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] == '.' && dist[nx][ny] > dist[x][y]) {
                dist[nx][ny] = dist[x][y];
                dq.push_front({nx, ny});
            }
        }

        for (int d = 0; d < 4; d++) {
            for (int step = 1; step <= 2; step++) {
                int nx = x + dx[d] * step, ny = y + dy[d] * step;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back({nx, ny});
                }
            }
        }
    }
    cout<< dist[C][D] << endl;
}

int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}