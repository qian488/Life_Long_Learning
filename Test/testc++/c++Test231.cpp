#include<iostream>

using namespace std;
//AtCoder Beginner Contest 343_A.Wrong Answer
typedef long long ll;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = a + b - 1;
    if (ans<0)
    {
        ans = 9;
    }
    cout << ans << endl;
    return 0;
}