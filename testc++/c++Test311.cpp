#include<bits/stdc++.h>
//蓝桥--门牌制作
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

int main()
{
    int ans = 0;
    for (int i = 1; i <= 2020; i++)
    {
        int t = i;
        while (t)
        {
            int d = t % 10;
            if(d==2)
                ans++;
            t /= 10;
        }
        
    }
    cout << ans;
    return 0;
}