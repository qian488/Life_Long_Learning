#include<bits/stdc++.h>
//蓝桥第 9 场 小白入门赛——贝贝的集合
using namespace std;
//理解题目意思就好做了，最后只会是1或者2
typedef long long ll;
#define endl "\n"
const int N = 1e5 + 10;

int main() 
{
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        que.push(x);
    }
    while (que.size() >= 2)
    {
        int t1 = que.top();
        que.pop();
        int t2 = que.top();
        que.pop();
        if (t1 != t2)
        {
            cout << 2 << endl;
            return 0;
        }
        que.push(t1 + 1);
    }
    cout << 1 << endl;

    return 0;
}