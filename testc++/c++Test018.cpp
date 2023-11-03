#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    //质数
    bool isPrime(int n);
    //回文数
    bool isPalindrome(int n);
    for (int  i = a; i <= b; i++)
    {
        if (isPrime(i) && isPalindrome(i))
        {
        cout << i << "\n";
        }
    }
    return 0;
}
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
        for (int i=2; i<=sqrt(n); ++i){
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
    else {
        return false;
    }
}
//超时，需要降时间复杂度
//线性筛