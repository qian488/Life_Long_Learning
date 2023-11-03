#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int l,r,n=0,t1,t2,t,sum=0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {//遍历区间，从左到右
        t1 = i;
        t2 = i;
        while (t1!=0)
        {//记录是几阶
            t1 /= 10;
            n++;
        }
        while (t2!=0)
        {//进行模拟运算
            t = t2 % 10;
            sum += pow(t, n);
            t2 /= 10;
        }
        if (sum==i)
        {//判断结果
            cout << i << " ";
        }
        //清零
        n = 0;
        sum = 0;
    }
    
    
    return 0;
}