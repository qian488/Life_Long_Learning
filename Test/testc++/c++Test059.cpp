#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//4h的难题
char a[101][101]={'o'},b[101][101];
int main()
{
    int n, d, ans = 0, cnt = 0;
    cin>>n>>d;
    string s;
    vector<string> v;
    int i, j, k, l;
    for(i=0;i<n;i++)
    {
        for (j = 0; j < d; j++)
        {
            cin >> a[i][j];
        }
        //s=s.substr(0,d);
        //cout<<s<<endl;
    }
    int maxn = max(n, d);
    for ( k = 0,i=0; k < maxn; k++,i++)
    {
        for ( l = 0,j=0; l < maxn; l++,j++)
        {
            b[k][l] = a[j][i];
            //cout << b[k][l] << " ";
            s = b[k];
        }
        //cout << s << endl;
        v.push_back(s);
        //cout << endl;
    }
    
    for (int i = 0; i < d; i++)
    {
        s = v[i];
        int t = 0;
        if ((t=s.find('x',t))!=string::npos)
        {
            cnt = 0;//清零，确保是连续的
        }
        else
        {
            cnt++;
            ans = max(ans, cnt);
        }
        
        
        /*
        int t = 0;
        if ((t=s.find('x',t))!=string::npos)
        {
            cnt = cnt;
        }
        else
        {
            cnt++;
        }
        */
        //只是记录了所有人有空的情况，但是不是记录连续的最大值
    }
    cout << ans;
    return 0;
}