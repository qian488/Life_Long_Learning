#include<iostream>
#include<algorithm>
using namespace std;
//语文成绩
//差分
const int N = 10000010;
int a[N], b[N];
void insert(int l,int r,int c)
{
    b[l] += c;
    b[r + 1] -= c;
}
int main()
{
    int n, p;
    cin >> n >> p;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        insert(i, i, a[i]);
    }
    int ans = 0x3f3f3f;
    while (p--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int l = x, r = y;
        insert(l, r, z);
        
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        //cout << "b:" << b[i] << endl;
    }
    
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, b[i]);
        //cout << "ans:" << ans << endl;
    }
      
    cout << ans;
    return 0;
}