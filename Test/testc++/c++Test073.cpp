#include<iostream>
#include<algorithm>
using namespace std;
//小朋友爱的水果
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l, r, x;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 1e9;
        for (int j = i; j < n; j++)
        {
            x = min(x, a[j]);
            //cout << "x:" << x << " ";
            //cout << "\n";
            l = i, r = j;
            ans = max(ans, (r - l + 1) * x);
            //cout << ans << " ";
        }
        
    }
    cout << ans;
    return 0;
}