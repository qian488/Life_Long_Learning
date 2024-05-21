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
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

map<char, int> dx = {{'N', 0}, {'S', 0}, {'E', 1}, {'W', -1}};
map<char, int> dy = {{'N', 1}, {'S', -1}, {'E', 0}, {'W', 0}};

void Solve()
{ // 构造
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0; // 水平与竖直分量
    for (int i = 0; i < n; i++){
        x += dx[s[i]];
        y += dy[s[i]];
	}
 
	if (x % 2 || y % 2) { // 水平或竖直分量不是偶数无法分配，最终不会在同一个点
        cout << "NO" << endl;
        return;
	}
 
	if (!x && !y && n == 2) { // 每个至少有一动
        cout << "NO" << endl;
        return;
	}
    
    // 均分分量
	x /= 2;
	y /= 2;

    // 以R开始
	cout << "R";
	x -= dx[s[0]];
	y -= dy[s[0]];
 
	for (int i = 1; i < n; i++) {
		if (abs(x - dx[s[i]]) < abs(x) || abs(y - dy[s[i]]) < abs(y)) { // 判断此次移动后水平与竖直分量的变化 比先前少就说明可以让R再动，输出R否则输出H
			cout << "R";
			x -= dx[s[i]];
			y -= dy[s[i]];
		}else{
            cout << "H";
        }
	}
    cout << endl;
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
