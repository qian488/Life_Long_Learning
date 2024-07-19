#include<iostream>

using namespace std;
//牛客小白月赛86--剪纸游戏
//dfs
const int N=1e3+10;
char p[N][N];
int a[N],b[N];//a[]记录每个连通块每一列的小方块数， b[]记录每个连通块每一行的小方块数 
int ans;

void dfs(int x, int y) 
{
    if(p[x][y] == '*') return ;
    else 
    {
        a[x] ++;
        b[y] ++;
        p[x][y] = '*';
    }
    dfs(x - 1, y);dfs(x + 1, y);
    dfs(x, y - 1);dfs(x, y + 1);
}

void encircle(int n,int m)
{
    for(int i = 1; i <= n + 1; i ++) p[i][0] = p[i][m + 1] = '*';
    for(int i = 1; i <= m + 1; i ++) p[0][i] = p[n + 1][i] = '*';
}

void resetab(int l1, int r1, int l2, int r2)
{
    for(int i = l1 - 1; i <= r1; i ++) a[i] = 0;
    for(int i = l2 - 1; i <= r2; i ++) b[i] = 0;
}

//判断此连通块是否为长方形， 若是，则ans + 1，若否，不做任何处理
void judge(int l1, int r1, int l2, int r2)
{
  //判断每一行小方块数是否相等
    for(int i = l1; i < r1; i ++)
        if(a[i] != a[i + 1] && a[i + 1] != 0)
            return ;
  //判断每一列小方块数是否相等
    for(int i = l2; i < r2; i ++)
        if(b[i] != b[i + 1] && b[i + 1] != 0)
            return ;
    ans ++;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>p[i][j];
        }
    }
    encircle(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(p[i][j] == '.')
            {
                dfs(i, j);
                int l1, r1, l2, r2;
              //记录连通块的位置
                for(l1 = 0; !a[l1]; l1 ++);
                for(r1 = l1; a[r1]; r1 ++);
                for(l2 = 0; !b[l2]; l2 ++);
                for(r2 = l2; b[r2]; r2 ++);
              //调用判断，处理
                judge(l1, r1, l2, r2);
                resetab(l1, r1, l2, r2);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}