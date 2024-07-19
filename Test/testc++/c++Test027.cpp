#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//开map存字符串和数字的对应关系
map<string,int>    n={
    {"one",1},{"a",1},{"another",1},{"first",1},
    {"two",4},{"both",4},{"second",4},
    {"three",9},{"third",9},
    {"four",16},
    {"five",25},
    {"six",36},
    {"seven",49},
    {"eight",64},
    {"nine",81},
    {"ten",0},
    {"eleven",21},
    {"twelve",44},
    {"thirteen",69},
    {"fourteen",96},
    {"fifteen",25},
    {"sixteen",56},
    {"seventeen",89},
    {"eighteen",24},
    {"nineteen",96},
    {"twenty",0}
};

//开vector存要放进来的数字
vector<int> que;

int main()    
{
    string en;

    for(int i=0;i<6;i++)//六个单词 
    {
        cin>>en;
        if(n.count(en)>0)//判断是否在n中存在对应的映射关系    
        {
            que.push_back(n[en]);
        }
    }

    sort(que.begin(),que.end());//sort默认是升序
        
    int ans=0;
    for(vector<int>::iterator it=que.begin();it!=que.end();it++)    
    {
        ans=ans*100+(*it);//每个字母对应的数最后都是两位数
    }
    cout<<ans;

    return 0;
}