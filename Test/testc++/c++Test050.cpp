#include<iostream>
#include<vector>
using namespace std;
//玩具谜题
#define N 1000000
int a[N], b[N], c[N];
vector<string> v;
int n, m, num = 0;
void sol()
{
    for (int i = 0; i < m;i++)
    {
        if (a[num]==b[i])
        {
            //需注意，是逆时针转
            num = (num - c[i]) % n;
            if (num<0)
            {
                num = n + num;
            }
        }
        else if (a[num]!=b[i])
        {
            
            num = (num + c[i]) % n;
        }
        cout << "num:" << num << " ans:" << v[num] << endl;
    }
    cout << v[num];
}
int main()
{
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> s;
        v.push_back(s);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i] >> c[i];
    }
    
    sol();

    return 0;
}