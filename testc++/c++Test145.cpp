#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//牛客练习赛120--选择交换
//题目还没完全看明白就已经结束了
typedef long long ll;
const int N=2*1e5;
ll v[N];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        bool flag=false;
        int n;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
        }
        
        if(flag)
        {
            cout<<"YES"<<endl;
            cout<<m<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<l[i]<<" "<<r[i]<<endl;
            }
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*
题解
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
typedef struct Change{
  //    值     原位置    排序后的位置
    int value, pos_ori, pos_now;
}Change;

Change a[N];
//  m   用于记录输出的位置
int m, output[N][2];

bool cmp1(Change x, Change y){return x.value < y.value;}
bool cmp2(Change x, Change y){return x.pos_ori < y.pos_ori;}
void OutPut(int x, int y);
bool judge_false(int n);
void judge_true(int n);

int main()
{
    int t, n;
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> t;
    while(t --)
    {
        m = 0;
        cin >> n;
      //输入值并记录原位置
        for(int i = 1; i <= n; i ++)
            cin >> a[i].value, a[i].pos_ori = i;
        //如果最大值加上非最小值，那么最小值将无法配对
        sort(a + 1, a + n + 1, cmp1);
        if(judge_false(n))
        {
            //把序列排序为初始时的顺序
            sort(a + 1, a + n + 1, cmp2);
          //可以通过交换时进行处理
            judge_true(n);
        }
    }

    return 0;
}
//判断是否可以通过交换
bool judge_false(int n)
{
    //需要两两相加得到的值
    int judge = a[1].value + a[n].value;
    for(int i = 1; i <= n; i ++)
    {
        if(a[i].value + a[n - i + 1].value != judge)
        {
            cout << "NO\n";
            return false;
        }
        a[i].pos_now = i;
    }
    return true;
}

void judge_true(int n)
{
  //遍历，如果和有序时的顺序不同则记录并交换
  //也就是每个都判断一次位置
    for (int i = 1; i <= n; i++)
        while(a[i].pos_now != i)
        {
            OutPut(i, a[i].pos_now);
            swap(a[i], a[a[i].pos_now]);
        }
    cout << "YES\n";
    cout << m << '\n';
    for(int i = 0; i < m; i ++)
        cout << output[i][0] << ' ' << output[i][1] << '\n';
}
//储存交换的位置
void OutPut(int x, int y)
{
    output[m][0] = x;
    output[m][1] = y;
    m ++;
}
*/