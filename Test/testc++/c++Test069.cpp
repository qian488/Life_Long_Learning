#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//7_4 折半（二分）查找
//搞不懂为什么只有一半的数据过了，剩下一半是什么情况？
//原来是如果有三个相同数据，取中间的位置
//用ans来记录答案吧
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    /*
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    */
    int num,ans=-1;
    cin >> num;
    while (num--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int l = b - 1, r = c + 1;
        while (l+1<r)
        {
            int mid = l + r >> 1;
            //cout << mid << " ";
            if (v[mid]>a)
            {
                r = mid;
                ans = r;
            }
            else if(v[mid]<a)
            {
                l = mid;
                ans = l;
            }
            else
            {
                ans = mid;
                break;
            }
            
        }
        if (v[ans]==a)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
    }
    
    return 0;
}