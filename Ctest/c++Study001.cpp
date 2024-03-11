#include<iostream>
#include<cmath>
using namespace std;
double log2(double x) {
    return log(x) / log(2);
}
void solve()
{
    int T=1;
    //cin >> T;
    while (T--)
    {
        for (int i = 10; i <= 1000;i++)
        {
            if (i*i>=50*i*log2((double)i))
            {
                cout << i << endl;
                break;
            }
            
        }
    }
    
}
int main()
{
    solve();
    return 0;
}