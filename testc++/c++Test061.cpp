#include<iostream>
#include<vector>
using namespace std;
//桂电的餐券
int n, m, k;
vector<int> a, b;

bool check()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        //二进制枚举b的子序列
        for (int j = 0; j < (1<<m); j++)
        {
            int sum = a[i];
            for (int k = 0; k < m; k++)
            {
                sum += b[k] * (j >> k & 1);
            }
            
            /*
            int bsum = 0;
            bsum += b[j];//求的是全部和，故不符合
            int sum = a[i] + bsum;
            */
            if (sum==k)
            {
                cnt++;
            }
            
        }
        
    }
    if (cnt>0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void sol()
{
    
    cin >> n >> m >> k;
    a.clear();//每解决完一次要清空，避免影响下次的解决
    b.clear();
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    if (check())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        sol();
    }
    return 0;
}