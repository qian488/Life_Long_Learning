//Codeforces Round 937 (Div. 4)_D.Product of Binary Decimals
#define OTHER
#ifndef OTHER

#include<iostream>
#include<algorithm>
#include<iomanip>
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
const int N=1e5;

int ans[]={10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111,100000};

bool ttt(int x)
{
    int tt = x;
    while (tt)
    {
        int d = tt % 10;
        if (!(d==0||d==1))
        {
            return false;
        }
        tt /= 10;
    }
    return true;
}

bool check(int x)
{
    if (x==1)
    {
        return true;
    }
    bool flag = false;
    for(auto e:ans){
        if (x%e==0)
        {
            flag |= check(x / e);
        }
        
    }
    return flag;
}

void Solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (check(n))
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
}

int main()
{
    ios 
    /*
    for (int i = 2; i <= N; i++)
    {
        if(ttt(i))
            cout << i << ",";
    }
    */
    Solve();
    //Codeforces Round 937 (Div. 4)
    return 0;
}

#else

#include<bits/stdc++.h>
using namespace std;
//tourist的解法
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> nums;
  for (int t = 1; t <= 32; t++) {
    string s = "";
    for (int i = 5; i >= 0; i--) {
      if (t & (1 << i)) {
        s += "1";
      } else {
        s += "0";
      }
    }
    nums.push_back(atoi(s.c_str()));
  }
  const int N = int(1e5) + 10;
  vector<bool> can(N, false);
  can[1] = true;
  vector<int> que(1, 1);
  for (int b = 0; b < int(que.size()); b++) {
    for (int x : nums) {
      if (x <= N / que[b]) {
        int to = que[b] * x;
        if (to < N && !can[to]) {
          can[to] = true;
          que.push_back(to);
        }
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << (can[n] ? "YES" : "NO") << '\n';
  }
  return 0;
}

#endif