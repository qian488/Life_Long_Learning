#include<iostream>
#include<vector>
using namespace std;
//牛客周赛 Round 33--小红煮汤圆
//从拆包的角度去模拟
int main() 
{
    int n, x, k;
    cin >> n >> x >> k;

    vector<int> res;
    int pack = 0;
    int left = 0;

    for (int i = 0; i < n; i++) 
    {
        left += x;
        pack++;
        while (left >= k) 
        {
            res.push_back(pack);
            left -= k;
            pack = 0;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) 
    {
        cout << res[i];
        if (i < res.size() - 1) 
        {
            cout << " ";
        }
    }

    return 0;
}