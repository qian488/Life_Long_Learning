#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//Codeforces Round 931 (Div. 2)_A.Too Min Too Max
typedef long long ll;
int a[101];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n;i++)cin >> a[i];
        sort(a, a + n );
        ll ans = abs(a[0] - a[n - 1]) + abs(a[n - 1] - a[1]) + abs(a[1] - a[n - 2]) + abs(a[n - 2] - a[0]);
        cout << ans << endl;
    }
    return 0;
}