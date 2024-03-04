#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//pta贪心专场--book
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
    A = (-1)*(a + b);
    B = (2 * n + 3) * (2 * n + 5) * a * b;
    C = 2 * n * f[1] - 2 * m - (2 * n + 2) * a - (n * n + 3 * n + 2) * b;
    double x1, x2;
    int d, k;
    d = B * B - 4 * A * C;
    x1 = (-B + sqrt(d)) / (2 * A);
    x2 = (-B - sqrt(d)) / (2 * A);
    k = max(x1, x2);
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