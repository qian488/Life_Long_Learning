#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//pta跨年挑战赛--奇因子之和
//求一行数的第二大奇因子之和
int main()
{
    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vector<int> num;
        for (int j = 1; j <= x && num.size() < 2; j++)
        {//枚举j从小到大
            if (x % j == 0 && (x / j) % 2 == 1)
            {//从大到小存入奇因子
                num.push_back(x / j);
                //cout << x / j << " ";
            }
            //超过两个退出循环，只要两个最大的
        }
        //cout << (num.size() == 1 ? num[0] : num[1]) << " ";
        //判断是一个还是两个，一个的话就本身，两个的话取第二个，即为第二大奇因子
        ans += num.size() == 1 ? num[0] : num[1];
    }
    cout << ans << endl;
   
    return 0;
}
/*
题解
   int n, x, res = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x;
        std::vector<int> vec;
        for (int j = 1; j <= x && vec.size() <= 2; j++)
        {
            if (x % j == 0 && (x / j)&1)
            {
                vec.push_back(x / j);
                cout << x / j << " ";
            }
                

        }
        cout << "res+="<<(vec.size() == 1 ? vec[0] : vec[1]) << endl;
        res += vec.size() == 1 ? vec[0] : vec[1];
    }
    std::cout << res << std::endl;
*/