#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> mids, ys;

bool check(vector<int> a,int mid,int k)
{
    int y = 0;
    for (int i = 0; i < a.size(); i++)
    {
        y += a[i] / mid;
        ys.push_back(y);
    }
    
    return y >= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = 1e9;
    while(l+1<r)
    {
        int mid = l + r >> 1;
        mids.push_back(mid);
        if (check(a,mid,k))
        {
            l = mid;
        }
        else 
        {
            r = mid;
        }
        
    }
    cout << l << endl;
    cout << "a[i]:";
    for (vector<int>::iterator it = a.begin(); it != a.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "y:";
    for (vector<int>::iterator it = ys.begin(); it != ys.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "mids:";
    for (vector<int>::iterator it = mids.begin(); it != mids.end();it++)
    {
        cout << *it << " ";
    }
        return 0;
}