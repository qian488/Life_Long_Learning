//蓝桥--七段码
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    int sum = 0;
    
    //有一段二极管发光; a,b,c,d,e,f,g
    int l1 = 7;
    //有两段二极管发光; ab,af,bc,bg,cg,cd,de,eg,ef,fg
    int l2 = 10;
    //有三段二极管发光; abf,abc,abg,afg,afe,bcd,bcg,bgf,bge,cgd,cgf,cge,cde,cdg,deg,def,efg
    int l3 = 16;//
    //有四段二极管发光; abcd,abcg,abcf,abge,abgf,abfe,afeg,bcde,bcdg,bcgf,bcge,bged,bgef,cdef,cdeg,cdgf,cgfa,cgfe,defg,defa
    int l4 = 20;
    //有五段二极管发光即有两端不发光; ab,ac,ad,ae,af,ag,bc,bd,be,bg,cd,cf,cg,de,df,dg,ef,eg,fg
    int l5 = 19;//
    //有六段二极管发光即有一端不发光; a,b,c,d,e,f,g
    int l6 = 7;//(找一段二极管不发光的：)
    //第七种情况，全部发光
    int l7 = 1;
    
    sum = l1 + l2 + l3 + l4 + l5 + l6 + l7;
    cout << sum << endl;
    return 0;
}
/*
//dfs+连通集

#include <iostream>
using namespace std;

const int N = 10;

int ans;
int p[N];
bool st[N];
int e[N][N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u)
{
    if(u == 8)
    {
        for (int i = 1; i <= 7; i ++) p[i] = i;
        
        for (int i = 1; i <= 7; i ++)
            for (int j = 1; j <= 7; j ++)
                if(e[i][j] && st[i] && st[j])
                    p[find(i)] = find(j);
        
        int cnt = 0;
        for (int i = 1; i <= 7; i ++)
            if(st[i] && p[i] == i)
                cnt ++;
        
        if(cnt == 1) ans ++;
        return;                
    }
    
    st[u] = 1;                // 打开第 u 个二极管
    dfs(u + 1);
    
    st[u] = 0;                // 关闭第 u 个二极管
    dfs(u + 1);
} 

int main()
{
    e[1][2] = e[1][6] = 1;
    e[2][1] = e[2][7] = e[2][3] = 1;
    e[3][2] = e[3][7] = e[3][4] = 1;
    e[4][3] = e[4][5] = 1;
    e[5][4] = e[5][7] = e[5][6] = 1;
    e[6][1] = e[6][7] = e[6][5] = 1;
    e[7][2] = e[7][3] = e[7][5] = e[7][6] = 1;
    
    dfs(1);
    
    cout << ans << endl;
    return 0;
}
*/