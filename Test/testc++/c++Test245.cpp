#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N = 1e6 + 10;

vector<int> find_max_form(vector<int> nums,int n,int nt)
{
    vector<int> res(n - nt + 1);
    deque<int> dq;
    for (int i = 1; i <= nt; i++)
    {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
  }
  int j = 0;
  for (int i = nt + 1; i <= n + 1; i++)
  {
      res[j++] = nums[dq.front()];
      // 更新队列，保持单调递增
      while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
      dq.push_back(i);
      // 移除超出窗口的列
      if (dq.front() <= i - nt) dq.pop_front();
  }
  return res;
}

vector<int> find_min_form(vector<int> nums,int n,int nt)
{
    vector<int> res(n - nt + 1);
    deque<int> dq;
    for (int i = 1; i <= nt; i++)
    {
        while (!dq.empty() && nums[i] <= nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
  }
  int j = 0;
  for (int i = nt + 1; i <= n + 1; i++)
  {
      res[j++] = nums[dq.front()];
      // 更新队列，保持单调递增
      while (!dq.empty() && nums[i] <= nums[dq.back()]) dq.pop_back();
      dq.push_back(i);
      // 移除超出窗口的列
      if (dq.front() <= i - nt) dq.pop_front();
  }
  return res;
}

void solve()
{
    int n, m, nt, mt;
    cin >> n >> m >> nt >> mt;
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0)); // 存图
    vector<vector<ll>> s(n + 1, vector<ll>(m + 1, 0));   // 求二维前缀和
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j];
      }
    }
    ll ans = 0;
    //找最大值最小值窗口的集合,水平方向
    vector<vector<int>> rows_max(n, vector<int>());
    vector<vector<int>> rows_min(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        rows_max[i] = find_max_form(g[i + 1], m, mt);
        rows_min[i] = find_min_form(g[i + 1], m, mt);
    }
    //竖着计算的滑窗最值，求出子矩阵的极差
    for (int j = 0; j < rows_max[0].size(); j++)
    {
      //生成竖着的数组
      vector<int> t1;
      vector<int> t2;
      t1.push_back(0);
      t2.push_back(0);
      for (int i = 0; i < n; i++)
      {
          t1.push_back(rows_max[i][j]);
          t2.push_back(rows_min[i][j]);
      }
      //获得子矩阵最值窗口
      vector<int> res1 = find_max_form(t1, n, nt);
      vector<int> res2 = find_min_form(t2, n, nt);
      //计算子矩阵极差
      vector<int> k(res1.size());
      for (int i = 0; i < res1.size(); i++)
      {
          k[i] = res1[i] - res2[i];
          int ii = i + nt;
          int jj = j + mt;
          ll sum = s[ii][jj] - s[ii - nt][jj] - s[ii][jj - mt] + s[ii - nt][jj - mt];
          ans = max(ans, sum * k[i]);
      }
    }
    cout << ans;
}

int main()
{
    ios
    solve();
    //蓝桥第 7 场 小白入门赛_6.矩阵X
    //思路是滑动窗口+二维前缀和
    return 0;
}