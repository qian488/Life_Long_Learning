#include<iostream>

using namespace std;
//莞工集训24.01.27--G
//二叉树？
//前缀和？
const int N = 1e5 + 10;
typedef long long ll;
ll s[N];
int main()
{
    int T;
    cin >> T;

    for (int i = 1; i < N; i++)
    {
        s[i] = s[i - 1] + ;
        
    }

    while (T--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = s[r] - s[l - 1];
        cout << ans << endl;
        for (int i = l; i <= r; i++)
        {
            cout << s[i] << " ";
        }
        
    }
    
    return 0;
}