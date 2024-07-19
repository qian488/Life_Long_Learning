#include <iostream>
#include <map>
#include <vector>
//三人行必有我师
using namespace std;

void sol() 
{
    int n;
    cin >> n;
    
    map<int, int> countMap;

    // 计算每个元素的出现次数
    for (int i = 0; i < n;i++)
    {
        int num;
        cin >> num;
        countMap[num]++;
    }
    bool ans = false;
    // 检查是否有任意一个元素出现至少三次
    for (auto& pair : countMap) 
    {
        if (pair.second >= 3) 
        {
            ans = true;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main() 
{
    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
    
    return 0;
}