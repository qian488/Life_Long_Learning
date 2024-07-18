#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
//pta_dfs专场-- Saving James Bond - Easy Version
//跳鳄鱼
/*
1.第一点能否跳（有关中心岛
2.边界情况
3.如何储存点，或者说如何储存这个图的连通集
*/
const int N=105;
int n,m;
int g[N][N];
bool vis[N][N];

bool canJump(int x, int y) 
{
    int dx = x * x;
    int dy = y * y;

    return dx + dy <= m * m;
}

bool dfs(int x, int y) 
{
    vis[x][y] = true;

    for (int i = 0; i < n; i++) 
    {
        if (!vis[g[i][0]][g[i][1]]) 
        {
            if (canJump(g[i][0] - x, g[i][1] - y))dfs(g[i+1][0], g[i+1][1]);
        }
    }

    if (canJump(100 - x, 100 - y))return true;

    return false;
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[i][0] = x+50;
        g[i][1] = y+50;
    }
    cout << (dfs(0, 0) ? "Yes" : "No") << endl;
    return 0;
}
/*ac代码
#include <iostream>
#include <cmath>
#include <vector>

#define MaxPointer 100
using namespace std;
struct Pointer
{
    int x;
    int y;
};

vector<Pointer> Graph(MaxPointer);
vector<bool> Visited(MaxPointer); //存储点是否被踩过
int jumpmaximum = 0;                   //007可以跳的最远距离
int pointernum = 0;

//作用：判断从中心可以调到那个鳄鱼头上
bool FirstJump(int i)
{
    int p1 = pow(Graph[i].x, 2);
    int p2 = pow(Graph[i].y, 2);
    int r = pow(jumpmaximum + 7.5, 2);
    if (p1 + p2 <= r)
    {
        return true;
    }
    return false;
}

//作用：判断从当前点能否跳到岸上去
//返回值： true 能
//         false 不能
bool IsSafe(int i)
{
    if (Graph[i].x + jumpmaximum >= 50 || Graph[i].x - jumpmaximum <= -50 ||
        Graph[i].y + jumpmaximum >= 50 || Graph[i].y - jumpmaximum <= -50)
    {
        return true;
    }
    return false;
}

//作用：判断能否从i点跳到j点
//返回值： true 能
//         false 不能
bool Jump(int i, int j)
{
    int dis = 0;
    dis = pow(Graph[i].x - Graph[j].x, 2) + pow(Graph[i].y - Graph[j].y, 2);
    return (jumpmaximum * jumpmaximum >= dis ? true : false);
}

bool DFS(int i)
{
    bool answer = false;
    int j = 0;
    Visited[i] = true; //表示i点已经踩过

    //能不能从当前点跳到岸上去
    if (IsSafe(i))
    {
        answer = true;
    }
    for (j = 0; j < pointernum; j++)
    {
        if (!Visited[j] && Jump(i, j))
        {
            answer = DFS(j);
            Visited[j] = false;
            if (answer == true)
            {
                break;
            }
        }
    }
    return answer;
}

void Save007()
{
    bool answer = false;

    for (int i = 0; i < pointernum; i++)
    {
        if (!Visited[i] && FirstJump(i))
        {
            answer = DFS(i);
            if (answer)
            {
                break;
            }
        }
    }

    if (answer)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}

int main()
{
    cin >> pointernum;
    cin >> jumpmaximum;

    //初始化所有顶点状态都是未访问过状态
    for (int i = 0; i < pointernum; i++)
    {
        Visited[i] = false;
    }

    for (int i = 0; i < pointernum; i++)
    {
        cin >> Graph[i].x >> Graph[i].y;
    }

    if (jumpmaximum >= 42.5)
    {
        cout << "Yes";
    }

    Save007();

    return 0;
}
*/