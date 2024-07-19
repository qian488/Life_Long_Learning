#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 //7_3 二分查找 
int main()
{
    int n, m;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        int l = 0, r = n;
        while (l+1<r)
        {
            int mid = l + r >> 1;
            if(v[mid]<=t)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if(v[l]==t)
        {
            cout << l+1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    
    return 0;
}