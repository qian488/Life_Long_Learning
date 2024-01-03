#include<iostream>
#include<string>
using namespace std;
//段错误
//不知道怎么检查，先跳过吧
const int N=10010;
int ne[N];
int main()
{
    
    string t,p;
    cin >> t >> p;
    t = " " + t;
    p = " " + p;
    int tl = t.size()-1;
    int pl = p.size()-1;
    
    /*
    int n, m;
    char t[N], p[N];
    cin >> n >> t+1 >> m >> p+1;
    int tl = n, pl = m;
    */
    //cout<<tl<<" "<<pl<<endl;

    for (int i = 2, j = 0; i <= pl; i++)
    {
        while (j&&p[i]!=p[j+1])
        {
            j = ne[j];
        }
        if (p[i]==p[j+1])
        {
            j++;
        }
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= tl; i++)
    {
        while (j&&t[i]!=p[j+1])
        {
            j = ne[j];
        }
        if (t[i]==p[j+1])
        {
            j++;
        }
        if (j==pl)
        {
            j = ne[j];
            cout << i - pl + 1 << endl;
        }
    }
    
    for (int i = 1; i <= pl; i++)
    {
        cout << ne[i] << " ";
    }
    
    return 0;
}
/*
//KMP模板
//求next数组
for(int i=2,j=0;i<=n;i++)
{
    while(j&&p[i]!=p[j+1]) j=ne[j];
    if(p[i]==p[j+1]) j++;
    ne[i]=j;
}
//匹配
for(int i=1,j=0;i<=m;i++)
{
    while(j&&s[i]!=p[j+1]) j=ne[j];
    if(s[i]==p[j+1]) j++;
    if(j==n)
    {
        cout<<i-n+1<<" ";
        j=ne[j];
    }
}
*/