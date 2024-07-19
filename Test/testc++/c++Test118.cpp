#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
//pta kmp专场--字符串匹配问题
//ＫＭＰ
//不知道怎么用kmp来写，但是感觉括号匹配应该是用stack会好写
const int N = 100010;
map<char, int> m = {
    {'<', 1}, {'>', 2}, 
    {'(', 3}, {')', 4}, 
    {'[', 5}, {']', 6},
    {'{', 7}, {'}', 8}
};
bool check(string str)
{
    stack<char> s;
    bool flag=true;
    for(char c:str)
    {
        if (s.empty())
        {
            s.push(c);
        }
        else
        {
            char top = s.top();
            if (m[c]%2==1)
            {
                if(m[c]<=m[top])
                {
                   s.push(c);
                }
                else
                {
                    flag=false;
                    break;
                }
            
            }
            else if (m[c]%2==0)
            {
                //cout<<m[c]%2+1<<" "<< m[top]%2<<endl;
                if (m[c]==m[top]+1)
                {
                    s.pop();
                }
            
            }
        }
        
        
        
    }
    return s.empty()&&flag;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string t;
        cin >> t;
        if (check(t))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
    
    return 0;
}
/*
KMP —— 模板题 AcWing 831. KMP字符串
求Next数组：
// s[]是模式串，p[]是模板串, n是s的长度，m是p的长度
for (int i = 2, j = 0; i <= m; i ++ )
{
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= n; i ++ )
{
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m)
    {
        j = ne[j];
        // 匹配成功后的逻辑
    }
}
*/
