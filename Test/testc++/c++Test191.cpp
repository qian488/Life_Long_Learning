#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
//牛客周赛 Round 30--小红构造回文
//模拟，因为原本就是回文，故将第一个与s[0]不等的字母对进行交换就是一个新的回文串
//通过90%,还有部分测试点没过，abcba
//okk，寻找不同的字符在前半段(不包含奇数长度的中心节点)，然后交换即可
int main() 
{
    string s;
    cin >> s;
    int n = s.length();

    int p = -1;
    for (int i = 1; i < n / 2; i++) 
    {
        if (s[0] != s[i]) 
        {
            p = i;
            break;
        }
    }
    // not found
    if (p == -1) 
    {
        cout << -1 << endl;
    } 
    else 
    {
        // swap
        swap(s[0], s[p]);
        swap(s[n - 1], s[n - 1 - p]);
        cout << s << endl;
    }

    return 0;
}