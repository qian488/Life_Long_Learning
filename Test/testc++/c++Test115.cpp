#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//大理石在哪里
int main()
{
    int cnt = 0;
    while (true)
    {
        int n, q;
        cin >> n >> q;
        if (n==0&&q==0)
        {
            break;
        }

        cout << "CASE# " << ++cnt << ":" << endl;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {//处理弹珠数目
            int t;
            cin >> t;
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < q; i++)
        {//处理询问
            int x;
            cin >> x;
            bool flag = false;
            for (int i = 0; i < n;i++)
            {
                if (v[i]==x)
                {
                    cout << x << " found at " << i+1 << endl;
                    flag = true;
                    break;
                }
                
            }

            if (!flag)
            {
                cout << x << " not found" << endl;
            }
            
        }
        
    }
    
    return 0;
}