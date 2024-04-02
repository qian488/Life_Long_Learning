#include<bits/stdc++.h>
//蓝桥杯——冶炼金属
using namespace std;
typedef long long ll;
#define MOD 1000000007
const int N=1e4+10;
//找左边区间最大值就是最小值，右边区间最小值就是最大值
int main()
{
	int n;
	cin>>n;
	int maxn=-1,minn=1e9;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		int l=a/(b+1)+1,r=a/b;
		maxn=max(maxn,l),minn=min(minn,r);
	}
	cout<<maxn<<" "<<minn<<endl;
	return 0;
}
/*
//二分解法
#include<bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;
const int N = 1e4 + 10;
int n;

int get(int a, int b)
{
    int l = 1, r = 1e9 + 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(a / mid <= b)
            r = mid;
        else l = mid + 1;
    }
    return r;
}

int main()
{
    cin >> n;
    
    int minv = 1, maxv = 1e9;
    int a, b;
    rep(i, 0, n)
    {
        scanf("%d%d", &a, &b);
        //对于所有的集合取交集
        minv = max(minv, get(a, b));
        maxv = min(maxv, get(a, b - 1) - 1);
    }
    
    cout << minv << " " << maxv;
    
    return 0;
}
*/