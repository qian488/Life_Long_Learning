#include<iostream>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;//防爆
//恒纪元
/*
思路：预处理 + STL

1）对于题目中 小蓝要向三体的领袖周文王预测下一个恒纪元是什么时候，并且能够持续多少年？ 
要知道下一个恒纪元是什么时候，恒纪元的下一个乱纪元又是什么时候。
这样一看好像要存两数组，但其实不用，在乱纪元中其实就有包含恒纪元，因为他俩是互补关系。

2）这样一来，我们直接处理区间中，哪些年份是乱纪元存在set中。

3）所以要找到下一个恒纪元，只需要从乱纪元的年份，从小到大往后找，找到跳变的距离大于1。

4）可以用lower_bound （二分） --- 返回一个迭代器
*/
int main()
{
    ll x, y, z, q;
    set<ll> s;//去重
    cin >> x >> y >> z;
    for (int i = 0; i <= 64; i++)
    {
        for (int j = 0; j <= 64; j++)
        {
            for (int k = 0; k <= 64; k++)
            {
                ll temp = pow(x, i) + pow(y, j) + pow(z, k);
                if (temp<=1e13)
                {
                    s.insert(temp);//存入所有符合条件的乱纪元
                }
                
            }
            
        }
        
    }
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        auto it = s.find(t);//找到该乱纪元在set中的位置
        //找下一个恒纪元
        while (*(it++)==t)//连续的都是乱纪元
        {
            t++;
        }

        auto pos = s.lower_bound(t);//二分查找第一个大于或等于t的数字
        cout << t << " " << *pos - t << endl;
    }
    
    return 0;
}
/*
不知道是哪方面，但是肯定爆了，跑不动
int T[1000000];
int main()
{
    int x,y,z,q,s,t;
    cin>>x>>y>>z;
    int m=0;
    for(int j=0;j<1e12;j++)
    {
        for(int k=0;k<1e12;k++)
        {
            for(int l=0;l<1e12;l++)
            {
                t=pow(x,j)+pow(y,k)+pow(z,l);
                T[m]=t;
                m++;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(T[j]>s)
            {
                cout<<T[j]<<" "<<T[j+1]-T[j+1]+1<<endl;
                break;
            }
        }
    }
    return 0; 
}
*/