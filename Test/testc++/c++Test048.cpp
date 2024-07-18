#include<iostream>
#include<cmath>

using namespace std;
//集合求和
int main()
{

    int sum = 0, a, ans, cnt = 0;
    while (cin>>a)
    {
        sum += a;
        cnt++;
    }
    ans = pow(2, cnt - 1) * sum;
    cout << ans;
    return 0;
}