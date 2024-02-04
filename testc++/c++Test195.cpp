#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
//莞工集训24.02.03--C
typedef long long ll;
const int N = 1e5 + 10;
double a[N];
int main()
{
    double maxn = 0, minn = 101;
    double avg;
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    avg = sum * 1.0 / n;
    cout << maxn << endl;
    cout << minn << endl;
    cout << fixed << setprecision(2) << avg << endl;
    return 0;
}