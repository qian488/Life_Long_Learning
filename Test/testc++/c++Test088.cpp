#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
//素因子
//dfs
#define N 1010
set<int> s;//记录素因子
int a[N];
int n, ans = 0x3f3f3f3f;

bool isPrime(int n) 
{
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }    
    } 
    return true;
}
//x表示个数，s表示记录的素因子，t表示最小素因子的累加和
void dfs(int x,set<int> s,int t)
{
    if (x==n)
    {
        ans = min(ans, t);
        return;
    }
    
    for (int i = 2; i <= a[x]; i++)
    {
        if ((a[x]%i==0)&&(isPrime(i))&&(!s.count(i)))
        {
            s.insert(i);
            //cout << i << " ";
            dfs(x + 1, s, t + i);
            s.erase(i);
        }
        
    }
    
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dfs(0, s, 0);
    if (ans==0x3f3f3f3f)
    {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}
