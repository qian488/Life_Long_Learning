#include<iostream>
#include<vector>
#include<set>
using namespace std;
//集合之差
int n,m;
set<int> s;
vector<set<int>> v(n);
bool check()
{
    
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
    for(int i = 0;i<t;i++)
    {
        sol();
    }
    return 0;
}