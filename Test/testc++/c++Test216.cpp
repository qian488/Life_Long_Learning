#include<iostream>
#include<vector>
using namespace std;
//Codeforces Round 928 (Div. 4)_C. Vlad and a Sum of Sum of Digits
typedef long long ll;
const int N = 2e5 + 10;
vector<ll> a(N);

ll sol(ll num) 
{
    ll sum = 0;
    while (num > 0) 
    {
        sum += num % 10; 
        num /= 10; 
    }
    return sum;
}

int main() 
{
    int t;
    cin >> t; 

    for (int i = 1; i <= N; i++) 
    {
        a[i] = a[i - 1] + sol(i);
    }

    while (t--) 
    {
        int n;
        cin >> n;

        cout << a[n] << endl;
    }

    return 0;
}