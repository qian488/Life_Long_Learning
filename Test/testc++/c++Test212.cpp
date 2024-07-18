#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Codeforces Round 927 (Div. 3)_C. LR-remainders
//暴力模拟会爆ll,需要从后向前算
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        ll sum = 1;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        string s;
        cin >> s;
        int l = 0, r = 0;
        for (int i = 0; i <= n; i++)
        {
            if(s[i]=='L')l++;
        }
        r = l;
        vector<int> ans;
        for (int i = n - 1; i >= 0;i--)
        {
            if (s[i]=='L')
            {
                sum = (sum * v[l--]) % m;
            }
            else if(s[i]=='R')
            {
                sum = (sum * v[++r]) % m;
            }
            ans.push_back(sum);
        }
        reverse(ans.begin(), ans.end());
        for(auto e:ans)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    
    return 0;
}