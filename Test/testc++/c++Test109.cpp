#include<iostream>
#include<map>
using namespace std;
//众数
map<int, int> m;
int main()
{
    int n;
    while (cin>>n)
    {
        m[n]++;
    }
    int maxCnt = 0;
    int maxNum = 0;
    for (auto e:m)
    {
        if (e.second>maxCnt)
        {
            maxCnt = e.second;
            maxNum = e.first;
        }
        
    }
    cout << maxNum << endl;
    return 0;
}