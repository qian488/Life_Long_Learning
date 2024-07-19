#include<iostream>
#include<set>
using namespace std;
//pta数论专场--Goldbach's Conjecture （哥德巴赫猜想）
const int N = 1e6 + 1;
set<int> p;
bool is_prime(int x)
{//判断是否是素数
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

void init()
{//预处理找好所有素数，存在集合中
    for (int i = 3; i < N; i++)
    {
        if (is_prime(i))
        {
            p.insert(i);
        }
        
    }
    
}

bool check(int x)
{//判断是否在集合中
    return p.count(x) > 0;
}

int main()
{
    init();
    while (1)
    {
        bool flag=false;
        int x;
        cin >> x;
        if (x==0)
        {
            break;
        }
        for (int i = 3; i < x; i++)
        {
            if (check(i)&&check(x-i))
            {//当输入的数，能够形成符合的数对就输出结果并退出循环，以实现找到绝对值最小
                cout << x << " = " << i << " + " << x-i << endl;
                flag=true;
                break;
            }
        }
        if(!flag)
        {//如果没有，输出错误信息
            {
                cout<<"Goldbach's conjecture is wrong.";
            }
        }
                
        
    }
    
    return 0;
}