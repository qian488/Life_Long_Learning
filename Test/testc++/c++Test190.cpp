#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//牛客周赛 Round 30--小红的正整数
//模拟，升序sort，然后找到第一个最小的数(!0)，然后放在最前面，即是答案
int main()
{
    string x;
    cin >> x;
    sort(x.begin(), x.end());
    int top_pos = -1;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != '0')
        {
            top_pos = i;
            break;
        }
    }
    if (top_pos>0)
    {
        swap(x[0], x[top_pos]);
    }
    cout << x;
    return 0;
}