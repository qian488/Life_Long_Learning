#include<iostream>
#include<vector>
#include<set>
using namespace std;
//集合之差
//set学习题，不过感觉二进制枚举或许也能做？
//不知道为什么运行不起来，额，之后再看吧，或许也不会再打开了
int n,m;
set<int> s;
vector<set<int>> v(n);
bool check()
{
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            set<int> dif;
            for(auto e:v[i])//遍历容器 v[i] 中的每个元素，并将每个元素赋值给变量 e
            {
                if(v[j].find(e)==v[j].end())//v[j]中找不到就返回最后的位置，即end
                {
                    dif.insert(e);
                }
            }
            if (dif==s)
            {
                ans = true;
            }
            
        }
        
    }
    return ans;
}

void sol()
{
    
    cin>>n>>m;
    
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        s.insert(t);
    }
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            int t;
            cin >> t;
            v[i].insert(t);
        }
        
    }
    if (check())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        sol();
    }
    
    return 0;
}