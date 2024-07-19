#include<bits/stdc++.h>
//蓝桥杯——后缀表达式
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 2e5 + 10;
int a[N];
int main()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n + m + 1; i++) cin >> a[i];
    sort(a , a + n + m + 1 );
    if(m==0)
        for (int i = 0; i < n + m + 1; i++) ans += a[i];
    else{
        ans = a[n + m ] - a[0];
        for (int i = 1; i < n + m; i++) ans += abs(a[i]);
    }
	cout<<ans;
    return 0;
}
//错误原因：后缀表达式转中缀表达式存在括号问题
/*50分
int l[N], r[N];
int main()
{
    int n, m, p = 0, q = 0;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n + m + 1; i++)
    {
		int x;
		cin>>x;
		ans+=x;
		if(x>0)//记录正数 
		{
            r[p++] = x;
        }
        else//记录非正数 
		{
            l[q++] = x;
        }
    }
	if(m==0)//负号个数为0
        cout << ans << endl;
    else if(m<q)//负号个数小于负数个数 
	{
        for (int i = 0; i < q; i++) ans -= l[i] * 2; // 第一遍相当于减掉了一次负数绝对值，第二遍时要补2倍
        cout << ans << endl;
    } 
	else//负号个数大于负数个数 
	{
        for (int i = 0; i < q; i++) ans -= l[i] * 2;
        sort(r, r + p);
        for (int i = 0; i < m - q; i++) ans -= r[i] * 2; // 第一遍已经加了一次正数，去掉时要减2倍
        cout << ans << endl;
    }
	return 0;
}
*/
/*30分
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> l,r;
    for (int i = 0; i < m + n + 1; i++)
    {
        int x;
        cin >> x;
        if(x<0) l.push_back(x);//负数
        else r.push_back(x);//正数
    }
    ll ans = 0;
    if(m==0){//没有减的操作，答案就是全部加起来
        for (int i = 0; i < r.size(); i++) ans += r[i];
        for (int i = 0; i < l.size(); i++) ans += l[i];
        cout << ans << endl;
        return 0;
    }
    //非空，排序
    if(!l.empty()) sort(l.begin(),l.end());
    if(!r.empty()) sort(r.begin(),r.end());

    if (l.size() >= m)//负数比减的操作数多，前t个负数变正数加入，后面的以负数形式加入
    {
        for (int i = 0; i < r.size(); i++) ans += r[i];
        int t = m;
        for (int i = 0; i < l.size(); i++, t--)
        {
            if(t>0) ans-=l[i];
            else ans+=l[i];
        }
    }else {//负数比减的操作数少，全部负数变正数加入，前t个正数变负数加入，后面以正数形式加入
        for (int i = 0; i < l.size(); i++) ans -= l[i];
        int t = m - l.size();
        for (int i = 0; i < r.size(); i++, t--)
        {
            if(t>0) ans-=r[i];
            else ans+=r[i];
        }
    }

    cout << ans << endl;
    return 0;
}
*/