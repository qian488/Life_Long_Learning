#include<iostream>
using namespace std;
//pta数论专场--Sum of Consecutive Prime Numbers（连续素数的和）
const int N = 1e5 + 10;
int p[N], cnt = 0;
bool vis[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            p[cnt++] = i;
        }
        for (int j = 0; p[j] <= n/i ; j++)
        {
            vis[p[j] * i] = true;
            if (i%p[j]==0)
            {
                break;
            }
            
        }
        
    }
    
}

int f(int x) 
{
    int res = 0;
    for (int i = 0; i < cnt; i++) 
    {
        int s = 0;
        int j = i;
        while (j < cnt && s < x) 
        {
            s += p[j];
            j++;
        }

        if (s == x) 
        {
            res++;
        }
    }

    return res;
}

int main()
{
    get_primes(N);
    /*
    for(auto e:p)
    {
        cout << e << " ";
    }
    */
    while (1)
    {
        int x;
        cin >> x;
        if (x==0)
        {
            break;
        }
        int ans = f(x);
        cout << ans << endl;
    }
    
    return 0;
}