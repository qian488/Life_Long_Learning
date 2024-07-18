#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
//现场游戏
//搞不明白为什么不能过，先放
set<string> table;
bool checkWin(const vector<string> v)
{
    int N = v.size();
    string s = "", s1 = "", s2 = "", s3 = "", s4 = "", t1 = "";
    
    for(auto e:v)
    {
        s += e;
    }
    if (table.count(s)>0)
    {
        return true;
    }

    //0°
    s1 = s;
    table.insert(s1);
    cout << "s1:" << s1 << endl;
    vector<string> vt(N, string(N, ' '));

    //翻转90°
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vt[j][N - i - 1] = v[i][j];
        }
        
    }
    for(auto e:vt)
    {
        s2 += e;
    }
    table.insert(s2);
    cout << "s2:" << s2 << endl;

    //180°
    reverse(s1.begin(), s1.end());
    s3 = s1;
    table.insert(s3);
    cout << "s3:" << s3 << endl;

    //270°
    reverse(s2.begin(), s2.end());
    s4 = s2;
    table.insert(s4);
    cout << "s4:" << s4 << endl;

    return false;
}
int main()
{
    int n;
    bool isFirst = true;
    while ((cin>>n)&&(n!=0))
    {
        table.clear();
        vector<string> v(n, string(n, 'o'));
        string ans;
        int cnt = 0;
        bool flag = false;
        for (int i = 1; i <= (2*n); i++)
        {
            int x, y;
            char op;
            cin >> x >> y >> op;
            x--, y--;
            cnt++;
            if (flag)
            {
                continue;
            }
            if (op=='+')
            {
                v[x][y] = 'x';
            }
            else if (op=='-')
            {
                v[x][y] = 'o';
            }
            if (cnt>=(2*n))
            {
                ans = "Draw";
                flag = true;
            }
            else if (checkWin(v))
            {
                ans = "Player " + to_string((i % 2) + 1) + " wins on move " + to_string(cnt);
                flag = true;
            } 
        }
        if (isFirst)
        {
            cout << ans;
            isFirst = false;
        }
        else
        {
            cout << endl
                 << ans;
        }
    }
    return 0;
}