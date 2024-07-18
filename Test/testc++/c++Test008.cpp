#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n, k,c_a=0,c_b=0,s_a=0,s_b=0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i%k!=0)
        {
            s_b += i;
            c_b++;
        }
        else
        {
            s_a += i;
            c_a++;
        }
    }
    cout << fixed << setprecision(1) << s_a*1.0/ c_a << " " << s_b*1.0 / c_b;
    return 0;
}