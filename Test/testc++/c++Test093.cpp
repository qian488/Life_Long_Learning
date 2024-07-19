#include<iostream>
#include<algorithm>
using namespace std;

//最大加权矩阵
//感觉这样时间复杂度很高，能过是题目放的松，应该还有别的解法
const int N = 150;
int main()
{
    int n;
    int a[N][N], b[N][N];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
        }
        
    }
    int ans=-999999;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = i; k <= n; k++)
            {
                for (int l = j; l <= n; l++)
                {
                    ans = max(ans, b[k][l] - b[i - 1][l] - b[k][j - 1] + b[i - 1][j - 1]);
                }
                
            }
            
            
        }
        
    }
    cout << ans;

    return 0;
}