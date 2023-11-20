#include<iostream>

using namespace std;
//数字三角形
//如果是100000的话，会导致栈溢出，以至于无法编译
//一周了，还没解决，好像是有关DP的题，但是没什么思路，就先去补其他题
#define N 10000
int a[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}