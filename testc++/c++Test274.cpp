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


void Solve()
{
    int n;
    cin >> n;

    vector<vector<int>> Necklace;
    deque<int> Pole;

    while (n--)
    {
        char ch;
        int num;
        cin >> ch >> num;
        if(num)
        {
            if (ch=='L') Pole.push_front(num);
            else if(ch=='R') Pole.push_back(num);
        }
        else
        {
            vector<int> tt;
            if (ch=='L')
            {
                while (Pole.size()&&Pole.front())
                {
                    tt.push_back(Pole.front());
                    Pole.pop_front();
                }
                
            }
            else if(ch=='R')
            {
                while (Pole.size()&&Pole.back())
                {
                    tt.push_back(Pole.back());
                    Pole.pop_back();
                }
                
            }
            if (Pole.empty()) Pole.push_back(0);
            Necklace.push_back(tt);
        }
    }
    for (auto e:Necklace)
    {
        cout << e.size() << " ";
        for(auto elem:e)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    ios 
    Solve();
    //莞工天梯赛预选赛_I.神奇项链
    return 0;
}