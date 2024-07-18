#include<iostream>
#include<cmath>
using namespace std;
//质数筛
int a[1000001];
bool Is_prime(int x)
{
    if (x<2)
    {
        return false;
    }
    else if(x==2)
    {
        return true;
    }
    else if (x%2==0)
    {
        return false;
    }
    else
    {
        for (int i = 3; i <= sqrt(x); i++)
        {
            if (x%i==0)
            {
                return false;
            }
            
        }
        return true;
    }
    
    
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (Is_prime(a[i]))
        {
            cout << a[i] << " ";
        }
        
    }
    
    return 0;
}