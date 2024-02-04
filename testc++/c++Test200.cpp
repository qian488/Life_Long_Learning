#include<iostream>

using namespace std;
//牛客周赛 Round 31 --小红的字符串中值
//还是超时
typedef long long ll;
char chr;
bool check(string s)
{
    int len = s.length();
    return s[len / 2] == chr;
}
int main()
{
    int n;
    cin >> n >> chr;
    string s;
    cin >> s;
    ll ans = 0;
    for (int l = 1; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;
            string st = s.substr(i, l);
            //cout << st << endl;
            if (st.length()%2==1)
            {
                if (check(st))
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}