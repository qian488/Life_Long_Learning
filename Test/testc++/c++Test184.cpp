#include<iostream>
#include<map>
using namespace std;
//蓝桥第 4 场 小白入门赛--自助餐
//暴力模拟
map<string, int> m;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    int ans = 0;
    for (auto e:m)
    {
        if (e.first=="yuanxing")
        {
            ans += e.second * 1;
        }
        else if(e.first=="zhengfangxing")
        {
            ans += e.second * 2;
        }
        else if(e.first=="changfangxing")
        {
            ans += e.second * 3;
        }
        else if(e.first=="sanjiaoxing")
        {
            ans += e.second * 4;
        }
        else if(e.first=="tuoyuanxing")
        {
            ans += e.second * 5;
        }
        else if(e.first=="liubianxing")
        {
            ans += e.second * 6;
        }
    }
    cout << ans;
    return 0;
}