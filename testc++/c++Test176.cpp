#include<iostream>
#include<iomanip>
//莞工集训24.01.27--A
//模拟
//想多了
using namespace std;
const int mod = 100000007;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    //n = n % mod;
    ll s = n / 1000;
    ll h = (s / 3600) % 24;
    ll m = (s % 3600) / 60;
    s = (s % 3600) % 60;
    cout << setfill('0');
    cout << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s;
    return 0;
}