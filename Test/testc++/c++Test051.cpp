#include<iostream>

using namespace std;
//数字三角形
//如果是100000的话，会导致栈溢出，以至于无法编译
//一周了，还没解决，好像是有关DP的题，但是没什么思路，就先去补其他题
#define N 10000
int a[N][N],b[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
            b[1][1] = a[1][1];
        }
        
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            b[i][j] = a[i][j] + max(b[i - 1][j], b[i - 1][j - 1]);
            //cout << b[i][j] << " ";
        }
        //cout << endl;
    }
    cout << max(b[n][(n + 1) / 2], b[n][(n + 2) / 2]);
    return 0;
}

/*
这题不是很懂
题解
#include <iostream>
using namespace std;
int a[200][200],c[200][200],n;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=i;j++)
  cin>>a[i][j];
  c[1][1]=a[1][1];
  for(int i=2;i<=n;i++)
  for(int j=1;j<=i;j++)
  c[i][j]=a[i][j]+max(c[i-1][j],c[i-1][j-1]);
  cout<<max(c[n][(n+1)/2],c[n][(n+2)/2]);
  return 0;
}
*/