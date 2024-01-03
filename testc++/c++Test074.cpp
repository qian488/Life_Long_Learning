#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//Median Pyramid Hard
//还有5个测试点没过
//有一种特殊情况。就是没有任何两个相邻的。需要特判
typedef long long ll;
const int N = 100010;
int a[2 * N];
int n, len;
bool check(int mid)
{

    for (int i = 0; i < n; i++)
    {//枚举判断中间距离两边
        if (((a[n+i]<=mid)&&(a[n+i+1]<=mid))||((a[n-i]<=mid)&&(a[n-i-1]<=mid)))
        {
            return true;
        }
        if (((a[n+i]>mid)&&(a[n+i+1]>mid))||((a[n-i]>mid)&&(a[n-i-1]>mid)))
        {
            return false;
        }
        
    }
    
    return a[1] <= mid;//特判重合
}
int main()
{
    cin >> n;
    len = 2 * n - 1;
    for (int i = 1; i <= len; i++)
    {
        cin >> a[i];
    }
    //sort(a, a + len);

    int l = 1;
    int r = len;
    while(l+1<r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r;

    return 0;
}
/*
题解
事实上，因为我们求得是中位数，所以每个数对我们来说只有与枚举的数的大小关系需要我们考虑，我们可以使大于这个数的数为1，其余的为0。

如此将其转化成一个01串，接下来我们讨论这个01串。

接下来我们可以小小的推一下。事实上，当有两个都为0的数或者都为1的数，那么就可以一直往上走。

*/