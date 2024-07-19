#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
//订单
set<string> v;
void sol(string s,int a,int b)
{
    if (a==b)
    {
        v.insert(s);
    }
    else
    {
        for (int i = a; i <= b; i++)
        {
            swap(s[a], s[i]);
            sol(s, a + 1, b);
        }
        
    }
}
int main()
{
    string s;
    cin >> s;
    sol(s, 0, s.length() - 1);
    for(auto e:v)
    {
        cout << e << endl;
    }
    return 0;
}
/*
递归交换tle
调用库函数next_permutation可以过
next_permutation 的实现是基于字典序算法的
具体来说，next_permutation 接受两个迭代器参数，表示一个范围，然后在这个范围内生成下一个（字典序中的下一个）排列。
如果存在下一个排列，则返回 true，否则返回 false。如果返回 true，范围内的元素顺序被修改为下一个排列。
int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());  // 将字符串排序为最小的排列

    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
*/