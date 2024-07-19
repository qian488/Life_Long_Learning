#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=1e6+10;

void printg(int n)
{
    for (int i = 1; i <= n; i++)
        {
            if (i%2==1)
            {
               for (int j = 1; j <= n; j++)
           {
            if (j%2==1)
            {
                cout << "##";
            }
            else{
                 cout << "..";
            }
               
              
           }
           cout << endl;
           for (int j = 1; j <= n; j++)
           {
               if (j%2==1)
            {
                cout << "##";
            }
            else{
                 cout << "..";
            }
              
           }
           cout << endl;
            }
            else{
                for (int j = 1; j <= n; j++)
           {
               if (j%2==1)
            {
                cout << "..";
            }
            else{
                 cout << "##";
            }
              
           }
           cout << endl;
           for (int j = 1; j <= n; j++)
           {
               if (j%2==1)
            {
                cout << "..";
            }
            else{
                 cout << "##";
            }
              
           }
           cout << endl;
            }
           
        }
}

void Solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        //printg(n);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                s += ((i + j) % 2 == 0 ? "##" : "..");
            }
            cout << s << endl;
            cout << s << endl;
        }
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 937 (Div. 4)_B.Upscaling
    return 0;
}