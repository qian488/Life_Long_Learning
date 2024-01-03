#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
//现场游戏
set<string> table;
bool checkWin(const vector<string> v)
{
    string s,s1,s2,s3,s4,t;
    //原本是否在table中
    for(auto e:v)
    {
        s += e;
    }
    s1 = s;
    //cout << "s1:" << s1 << endl;
    vector<string> vt = v;

    //翻转90°是否在table中
    for(auto e:vt)
    {
        reverse(e.begin(), e.end());
        s2 += e;
    }
    //cout << "s2:" << s2 << endl;
    t = s2;
    reverse(t.begin(), t.end());
    s4 = t;
    //翻转180°是否在table中
    reverse(vt.begin(), vt.end());
    for(auto e:vt)
    {
        reverse(e.begin(), e.end());
        s3 += e;
    }
    //cout << "s3:" << s3 << endl;
    if (table.count(s)>0)
    {
        return true;
    }
    table.insert(s1);
    table.insert(s2);
    table.insert(s3);
    table.insert(s4);
    return false;
}
int main()
{
    int n;
    bool isFirst = true;
    while ((cin>>n)&&(n!=0))
    {
        table.clear();
        vector<string> v(n, string(n, ' '));
        string ans;
        int cnt = 0;
        bool flag = false;
        
        for (int i = 1; i <= (2*n); i++)
        {
            int x, y;
            char op;
            cin >> x >> y >> op;
            x--;
            y--;
            cnt++;
            if (flag)
            {
                continue;
            }
            
            if (op=='+')
            {
                v[x][y] = 'o';
            }
            else if (op=='-')
            {
                v[x][y] = ' ';
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
            /*
            string test;
            for(auto e:v)
            {
                test += e;
            }
            cout << "test:" << test << endl;
            */

           //cout << "Draw" << endl;
           //break;
           //cout << "Player " << ((i % 2) + 1) << " wins on move " << cnt << endl;
           //break;