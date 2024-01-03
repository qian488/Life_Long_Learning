#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
//sb,一个排序就能解决
/*
int main() 
{
    int n;
    int minn = 1000000000;
    vector<int> v;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
        cnt++;
        for (int j = 0; j < cnt-1; j++)
        {
            if (t==v[j])
            {
                cout << 0 << endl;
                return 0;
            }
            
            minn = min(minn, abs(t - v[j]));
        }
    }
    cout << minn<< endl;
    
    return 0;
}
*/

int main()
{
    int n;
    int v[100000];
    int minn = 1000000000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v+n);
    for (int i = 1; i < n; i++)
    {
        minn = min(minn, v[i]-v[i-1]);
    }
    
    cout << minn << endl;
    return 0;
}
