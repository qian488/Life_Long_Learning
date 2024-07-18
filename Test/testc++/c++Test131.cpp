#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//pta贪心专场--book
//构造
typedef long long ll;
const int N = 1e5 + 10;
ll f[N],A[N],sa[N];
bool vis[N];//1表示-b,0表示+a操作
int main()
{
    int n;
    cin >> n;
    int a, b, m;
    cin >> f[1] >> a >> b >> m;
    ll sum = n * f[1];
    for (int i = 2; i <= n;i++) A[i] = A[i-1]+a;
    for (int i = 1; i <= n;i++) sa[i] = sa[i-1]+A[i];
    sum += sa[n];
    cout << sum << "\n";
    vis[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(sum>m)
        {
            sum-=(n-i+1)*(a+b);
            vis[i]=1;
        }
        else if(sum<m)
        {
            sum+=(n-i+1)*(a+b);
            vis[i-1]=0;
        }
        else if(sum==m) break;
    }

    cout << f[1] << " ";
    for (int i = 2; i <= n;i++)
    {
        
        if(!vis[i])
        {
            f[i] = f[i - 1] + a;
        }
        else
        {
            f[i] = f[i - 1] - b;
        }
        
        cout << f[i] << " ";
    }
    return 0;
}
/*思路错了
//过了样例，想不到，先看后面
//还是不行。。。问题在哪？
const int N = 1e5 + 10;
int f[N];
int main()
{
    int n;
    cin >> n;
    int a, b, m;
    cin >> f[1] >> a >> b >> m;

    int A, B, C;
    A = (-1) * (a + b);
    B = (2 * n + 1) * (a + b);
    C = (2 * n * f[1]) - 2 * m - (2 * a * n + n * n * b + n * b);
    double x1, x2;
    int d, k = 0;
    d = B * B - 4 * A * C;
    x1 = (-B + sqrt(d)) * 1.0 / (2 * A);
    x2 = (-B - sqrt(d)) * 1.0 / (2 * A);
    if(x1>=1&&x1<=n){k=x1;}
    else if(x2>=1&&x2<=n){k=x2;}

    cout << f[1] << " ";
    for (int i = 2; i <= n;i++)
    {
        
        if(i<k)
        {
            f[i] = f[i - 1] + a;
        }
        else
        {
            f[i] = f[i - 1] - b;
        }
        
        cout << f[i] << " ";
    }
    return 0;
}
*/
/*
    A = (-1)*(a+b);
    B = (2*n+1)*(a+b);
    C = 2 * n * f[1] - 2 * m - (2*a*n+n*n*b+n*b);
*/
/*
#include<iostream>

using namespace std;
//pta贪心专场--book
const int N = 1e5 + 10;
int A[N];
int main()
{
    int n;
    cin >> n;
    int a, b, sum;
    cin >> A[1] >> a >> b >> sum;
    sum -= A[1];
    cout << A[1] << " ";
    for (int i = 2; i <= n;i++)
    {
        int s = A[1];
        if(s+A[i-1]+a<sum)
        {
            A[i] = A[i - 1] + a;
        }
        else
        {
            A[i] = A[i - 1] - b;
        }
        sum -= A[i];
        s += A[i];
        cout << A[i] << " ";
    }
    return 0;
}
*/