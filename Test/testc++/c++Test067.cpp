#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//疯牛
//二分又是只能过样例，果然还是不怎么懂二分
bool check(vector<int> v,int mid,int c)
{
    int last=0,cnt=1;
    for (int i = 0;i<v.size();i++)
    {
        if(v[i]-v[last]>=mid)
        {
            cnt++;
            last = i;
        }
        
    }
    return cnt >= c;
}
int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int l = 0, r = v[n - 1] - v[0] ;
    while (l+1<r)
    {
        int mid = l + r >> 1;
        if(check(v,mid,c))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << endl;

    return 0;
}