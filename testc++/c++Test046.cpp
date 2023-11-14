#include<iostream>
#include<cmath>
using namespace std;
//回文质数

//判断是否是质数
bool isPrime(int n) {
    if (n==1)
    {
        return false;
    }
    else if(n%2==0)
    {
        return false;
    }
    else
    {
        for (int i=2; i<=sqrt(n); ++i)
        {
        if (n % i == 0)
        {
            return false;
        }    
        } 
    return true;
    }
    
}
//判断是否是回文
bool isPalindrome(int n)
{
    int t = n, num = 0;
    while (t != 0)
    {
        num = num * 10 + t % 10;
        t /= 10;
    }
    if (num==n)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    
    
	if(a % 2 == 0) a++; 
	b = min(9999999, b);

    for (int  i = a; i <= b; i++)
    {
        if (isPalindrome(i))
        {
            if(isPrime(i))
            {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}