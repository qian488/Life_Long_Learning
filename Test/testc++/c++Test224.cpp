#include<iostream>
#include<vector>
using namespace std;
//牛客周赛 Round 34_小红的陡峭值
//构造
/*题解思路
这题是限制性很强的题， 绝对差值总和为1
对于不满足条件数组，可以立马返回 -1.
难点在于如何构造合法数组
假定0元素(左右两侧都存在非0值)，和左侧元素保持一致（反证法使得该假设一定成立）
那就剩下一侧有非0值的0值，如何讨论呢？
如果绝对差值总和为1
那就和左侧/右侧的那个非0值，保持一致
如果绝对差值总和为0
那就选一边构造一个比左侧/右侧刚好大1的数
*/
int main() 
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (a == vector<int>(n, 0)) 
    {
        if (a.size() == 1) cout << -1 << endl;
        else 
        {
            cout << 1;
            for (int i = 1; i < n; i++) cout << " " << 2;
            cout << endl;
        }
    } 
    else 
    {
        vector<int> b;
        for (int v : a) if (v > 0) b.push_back(v);

        int t = 0;
        for (int i = 0; i < b.size() - 1; i++) t += abs(b[i] - b[i + 1]);

        if (t > 1) cout << -1 << endl;
        else 
        {
            int first = -1, last = -1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != 0) 
                {
                    if (first == -1) first = i;
                    last = i;
                }
            }

            int pre = a[first];
            for (int i = first + 1; i < last; i++) 
            {
                if (a[i] == 0) a[i] = pre;
                else pre = a[i];
            }

            if (t == 1) 
            {
                for (int i = 0; i < first; i++) a[i] = a[first];
                for (int i = last + 1; i < n; i++) a[i] = a[last];
                for (int i = 0; i < n; i++) cout << a[i] << " ";
                cout << endl;
            } 
            else
            {
                if (first > 0) 
                {
                    for (int i = 0; i < first; i++) a[i] = a[first] + 1;
                    for (int i = last + 1; i < n; i++) a[i] = a[last];
                    for (int i = 0; i < n; i++) cout << a[i] << " ";
                    cout << endl;
                } 
                else if (last + 1 < n) 
                {
                    for (int i = last + 1; i < n; i++) a[i] = a[last] + 1;
                    for (int i = 0; i < n; i++) cout << a[i] << " ";
                    cout << endl;
                } 
                else 
                {
                    cout << -1 << endl;
                }
            }
        }
    }

    return 0;
}