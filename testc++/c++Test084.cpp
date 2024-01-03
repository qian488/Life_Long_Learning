#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//充能计划
/*
参考题解修改原本的方法
邻接表＋区间合并
*/
typedef long long ll;
const int N = 2e5 + 5;//好像会超过1e5
int b[N],ans[N]={0};//ans数组记录的是每个位置的充能次数
vector<int> v[N];//数组v，其中每个元素都是一个vector<int>类型的向量,相当于一个二维数组
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)//每类宝石的能量
    {
        cin >> b[i];
    }
    
    for (int i = 1; i <= q; i++)
    {
        int p, k;
        cin >> p >> k;//种类p,扔到位置k
        v[p].push_back(k);
    }

    for (int i = 1; i <= m; i++)//枚举宝石的种类
    {
        sort(v[i].begin(), v[i].end());//将同类宝石所扔的位置进行排序
    }
    
    for (int i = 1;i<=m;i++)
    {
        int l, r, p_l = 0, p_r = 0;
        for (int j = 0; j < v[i].size(); j++)//枚举同一种宝石充能的位置
        {
            l = v[i][j], r = v[i][j] + b[i] - 1;//v[i][j]指的是k,b[i]指的是si,即此类宝石的能量
            cout << "l:" << l << "r:" << r << endl;
            if (l>p_r)//左边界大于上一次的右边界，说明没有重合
            {
                ans[l]++, ans[r + 1]--;
            }
            else//有重合部分
            {
                ans[p_r + 1]++, ans[r + 1]--;
            }
            //还是不太明白这部分的逻辑
            p_l = l, p_r = r;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] << " ";
    }
    
    return 0;
}


/*
搞不明白。。。
暴力模拟
第一次 种类1给【1，2】充能，有【1，1，0，0，0】
第二次 种类2给【3，5】充能，有【1，1，1，1，1】
位置2被同类充过，故不需要增加
第三次 种类1给【2，3】充能，有【1，1，2，1，1】
刚开始没完全解决重合部分的问题
样例的结果是0 1 2 1 1
但是正确答案应该是1 1 2 1 1
#define N 100000
int n, m, q;
int b[N],ans[N]={0};
int f[N]={0};
int main()
{
    
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    
    for (int i = 1; i <= q; i++)
    {
        int p, k;
        cin >> p >> k;
        f[i-1] = p;
        int l = k, r = min(k + b[p] - 1, n);
        //cout << r << endl;
        cout << p <<" "<< f[i] << endl;
        for (int j = 0; j < i; j++)
        {
            if (p!=f[j])
            {
            
            for (int t = l; t <= r; t++)
            {
                if (ans[t]<b[p])
                {
                    ans[t]++;
                }
                    
            }
            }
        }
        
    }
    
    
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}
*/