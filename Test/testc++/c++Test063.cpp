#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//原来你也玩原神
/*
思路
定义一个二维数组 students，大小为 m 行 n 列。
读取输入，将每个学生的原神编号和能力值存入 students 数组中对应的位置。
对于每种原神，按照能力值从高到低进行排序，如果有多个学生的能力值相同，则按照编号升序进行排序。
输出每种原神的实力排行，如果该种原神无人游玩，则输出 -1。
*/
bool cmp(const pair<int,int>& a,const pair<int,int>&b)
{
    if (a.second==b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int, int>>> s(m + 1);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        s[a].push_back(make_pair(i, b));
    }

    for (int i = 1; i <= m; i++)
    {
        if (s[i].empty())
        {
            cout << -1 << endl;
        }
        
        sort(s[i].begin(), s[i].end(), cmp);
        for (auto s:s[i])
        {
            cout << s.first + 1 << " ";
        }
        cout << endl;
    }
    
    /*
    for(map<int,int>::iterator it = maps.begin(); it != maps.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    */
    
    return 0;
}