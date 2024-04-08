#include<bits/stdc++.h>
//3
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
    int ans = 0;
    for (int i = 1; i <= 2020; i++)
    {
        for (int j = 1; j <= 2020; j++)
        {
			if(gcd(i,j)==1) ans++;
		} 
        
    }
    cout << ans;
    return 0;
}