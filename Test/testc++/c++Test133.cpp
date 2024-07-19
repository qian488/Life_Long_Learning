#include<iostream>
#include<string>
using namespace std;
//pta_KMP专场--KMP字符串匹配
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
/*
ac题解
#include <iostream>
#include <vector>
using namespace std;

void get_next(const string &p, vector<int> &ne) {
    int m = p.size();
    ne.resize(m + 1);
    ne[0] = -1;
    int k = -1;
    for (int i = 1; i <= m; i++) {
        while (k != -1 && p[i - 1] != p[k]) {
            k = ne[k];
        }
        ne[i] = ++k;
    }
}

void kmp(const string &t, const string &p) {
    int n = t.size();
    int m = p.size();
    vector<int> ne;
    get_next(p, ne);

    vector<int> positions; // 存储出现的位置

    int i = 0, j = 0;
    while (i < n) {
        while (j != -1 && t[i] != p[j]) {
            j = ne[j];
        }
        i++;
        j++;
        if (j == m) {
            positions.push_back(i - m + 1);
            j = ne[j];
        }
    }

    // 输出出现的位置
    for (int pos : positions) {
        cout << pos << endl;
    }

    // 输出前缀数组next
    cout<<ne[1];
    for (int i=2;i<=m;i++) {
        cout << " ";
        cout<<ne[i];
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    kmp(text, pattern);

    return 0;
}
*/