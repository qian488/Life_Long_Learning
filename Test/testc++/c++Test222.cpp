#include<iostream>

using namespace std;
//HUAWEI Programming Contest 2024（AtCoder Beginner Contest 342_B.Which is ahead?
const int N = 101;
int p[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int t;
        cin >> t;
        p[t] = i;
    }  
    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(p[a]<p[b])
        {
            cout << a << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
    return 0;
}