#include<iostream>
#include<vector>
using namespace std;
//Codeforces Round 930 (Div. 2)_B.Binary Path
typedef long long ll;
const int N = 2e5 + 10;
vector<vector<char>> v(2,vector<char>(N));
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 2;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                cin >> v[i][j];
            }
        }
        int max_down = n, min_down = 1;

        for (int i = n; i >= 2; i--)
        {
            if(v[0][i]=='1'&&v[1][i-1]=='0')max_down = i - 1;
        }

        for (int i = 1; i < max_down; i++)
        {
            if(v[1][i]=='1'&&v[0][i+1]=='0')min_down = i + 1;
        }

        int cnt = max_down - min_down + 1;
        for (int i = 1; i <= max_down;i++)cout << v[0][i];
        for (int i = max_down; i <= n;i++)cout << v[1][i];
        cout << "\n";
        cout << cnt << endl;
    }
    return 0;
}