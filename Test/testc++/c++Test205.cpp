#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//莞工集训24.02.17--H
typedef long long ll;
int main() 
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) 
    {
        int x = A[i] % K;  // 当前数字与 K 的余数
        ans += (A[i] - x);  // 将数字减去余数，使其变为 K 的倍数
        if (i < N - 1) 
        {
            A[i + 1] -= x;  // 将余数分摊给下一个数字
        }
    }

    cout << ans << endl;

    return 0;
}