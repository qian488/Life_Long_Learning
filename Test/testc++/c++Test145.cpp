#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//牛客练习赛120--选择交换
//题目还没完全看明白就已经结束了
//跟着题解的思路，突然发觉用make_pair会容易些
//只过了十分之一的测试点
//想不到，先放了
typedef long long ll;
const int N = 2 * 1e5 + 10;
int a[N], b[N], c[N];
bool cmp(int x,int y)
{
    return a[x] < a[y];
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        bool flag = true;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            b[i] = i;
        }
        sort(b + 1, b + n + 1, cmp);
        //a[]存的是输入的数值，b[]存的是给a[]排序后的原下标
        int sum = a[b[1]] + a[b[n]];
        int cnt = 0;
        int m = n >> 1;
        for (int i = 1; i <= n; i++)
        {
            cnt++;
            if (sum!=a[b[i]]+a[b[n-i+1]])
            {
                if (cnt>=m)
                {
                    flag = false;
                }
                break;
            }
            
        }
        
        if(flag)
        {
            cout<<"YES"<<endl;
            cout<<m<<endl;

            for (int i = 1; i <= n; i++) 
            {
                c[b[i]] = i;
            }

            for (int i = 1; i <= n; i++)
            {
                cout << a[b[i]] << " ";
            }
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << b[i] << " ";
            }
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << c[i] << " ";
            }
            cout << endl;

            vector<pair<int, int>> swaps;
            for (int i = 1; i <= m; i++) 
            {
                swaps.push_back({c[i], c[n - i + 1]});
            }

            for (auto swap : swaps) 
            {
                cout << swap.first << " " << swap.second << endl;
            }
            
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}
