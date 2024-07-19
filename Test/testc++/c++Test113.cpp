#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
//组合
map<string, int> m;//存组合编号
int main()
{
    int n;
    while((cin>>n)&&(n!=0))
    {
        m.clear();//每次操作清空
        while(n--)
        {
            vector<int> v;//存读入的5个课程
            string s="";//记录课程编号
            for (int i = 0; i < 5;i++)
            {//输入数据
                int t;
                cin >> t;
                v.push_back(t);
            }
            sort(v.begin(), v.end());//排序
            for (int i = 0; i < 5;i++)
            {
                s += to_string(v[i]);
            }
            m[s]++;//按编号存入，并计数

            //cout << s << " ";
        }

        int cnt = 1;
        int tot = 0;
        for(auto e:m)
        {
            if (e.second>cnt)
            {//找出计数最大，即最受欢迎，并将该值赋给答案
                cnt = e.second;
            }
        }

        for(auto e:m)
        {
            if(e.second==cnt)
            {//记录有多少个最受欢迎组合
                tot++;
                //cout<<tot<<" ";
            }
        }
        
        if(cnt==1)
        {//1说明每个人的课程编号都不同，即所有组合都是最受欢迎
            cnt = m.size();
        }
        else if(tot)
        {//如果有多个最受欢迎组合，多个组合的人数都要输出
            cnt=cnt*tot;
        }

        cout << cnt << endl;//输出结果
    }

    return 0;
}