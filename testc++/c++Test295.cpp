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
    int h, w;
    cin >> h >> w;
    vector<string> grid;
    for (int i = 0; i < h;i++){
        string s;
        cin >> s;
        grid.push_back(s);
    }
    vector<vector<int>> degree(h, vector<int>(w, 0)); 
    vector<vector<bool>> visited(h, vector<bool>(w, false));  

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int maxDegree = 0; 

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') {
                continue;  
            }

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            degree[i][j] = 1;

            while (!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = curr.first + dx[k];
                    int ny = curr.second + dy[k];

                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == '.' && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        degree[i][j]++;
                        q.push({nx, ny});
                    }
                }
            }
            maxDegree = max(maxDegree, degree[i][j]); 
        }
    }

    cout << maxDegree << endl;
}

int main()
{
    ios 
    
    Solve();
    //AtCoder Beginner Contest 351_D	Grid and Magnet
    return 0;
}