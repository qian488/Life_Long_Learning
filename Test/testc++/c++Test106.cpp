#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//利用stl比较数据大小并排序
vector<int> v;
int main()
{
    int t;
    while (cin>>t)
    {
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    cout<<"从标准设备读入数据，直到输入是非整型数据为止"<<endl;
    for (auto e:v)
    {
        cout << " " << e;
    }
    return 0;
}