#include<iostream>
#include<vector>
using namespace std;
//牛客周赛 Round 33--小红煮汤圆
int main()
{
    vector<int> ans;
    int n, x, k;
    cin >> n >> x >> k;
    int cnt = n * x / k;
    int a = 0;
    for (int i = 0; i < cnt; i++)
    {
        int t = k / (x + a);
        a = (k + a) % x;
        if (a != 0) t++;
        ans.push_back(t);
    }
    
    cout << ans.size() << endl;
    for(auto e:ans)
    {
        cout << e << " ";
    }
    return 0;
}