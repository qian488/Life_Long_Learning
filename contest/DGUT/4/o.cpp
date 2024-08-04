#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"

using namespace std;

int n,m;
int coin[800][3200];
int len[11] = {0, 1, 2, 5, 11, 23, 47, 95, 191, 383, 767};
set<int> de[15];

void DrawL(int x, int y, int s)
{
    coin[y][x] = '/' - '0';
    if (s) DrawL(x - 1, y + 1, s - 1);
}

void DrawR(int x,int y,int s) {
    coin[y][x] = '\\' - '0';
    if (s) DrawR(x + 1, y + 1, s - 1);
}

void DrawNode(int x,int y,int level,int high,int p) {
    coin[y][x] = 'o' - '0';
    if (level!=0) {
        if (!de[high + 1].count((p << 1) - (1 << high) + 1))
        {
            DrawNode(x - len[level] - 1, y + len[level] + 1, level - 1, high + 1, p << 1);
            DrawL(x - 1, y + 1, len[level] - 1);
        }
        if (!de[high + 1].count((p << 1) + 1 - (1 << high) + 1))
        {
            DrawNode(x + len[level] + 1, y + len[level] + 1, level - 1, high + 1, (p << 1) + 1);
            DrawR(x + 1, y + 1, len[level] - 1);
        }
    }
 }
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        de[a].insert(b);
    }
    DrawNode(len[n], 0, n - 1, 1, 1);
    for (int i = 0; i < len[n] + 1; i++)
    {
        for (int j = 0; j < len[n] * 2 + 1; j++)
        {
            cout << (coin[i][j] ? (char)(coin[i][j]+'0') : ' ');
        }
        cout<<endl;
    }
    return 0;
}