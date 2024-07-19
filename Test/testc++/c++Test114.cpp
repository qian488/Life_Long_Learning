#include<iostream>
#include<map>
#include<string>
using namespace std;
//487-3279
//部分正确，有三个测试点没过
//如果输入数据中没有重复的号码，输出一行：No duplicates.问题出现在这个。
map<char, char> m = {
    {'A', '2'}, {'B', '2'}, {'C', '2'}, 
    {'D', '3'}, {'E', '3'}, {'F', '3'}, 
    {'G', '4'}, {'H', '4'}, {'I', '4'}, 
    {'J', '5'}, {'K', '5'}, {'L', '5'}, 
    {'M', '6'}, {'N', '6'}, {'O', '6'}, 
    {'P', '7'}, {'R', '7'}, {'S', '7'}, 
    {'T', '8'}, {'U', '8'}, {'V', '8'}, 
    {'W', '9'}, {'X', '9'}, {'Y', '9'}
};
map<string, int> ma;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string t,temp="";
        cin >> t;
        for(char c:t)
        {
            if (c>='0'&&c<='9')
            {//处理数字
                temp.push_back(c);
            }
            else if(c>='A'&&c<'Z'&&c!='Q')
            {//处理字母对应
                temp.push_back(m[c]);
            }
            
        }
        string s;
        s = temp.insert(3, 1, '-');//将号码标准化
        ma[s]++;//存入表中计数
    }

    bool flag = false;
    for(auto e:ma)
    {
        if (e.second>1)
        {//有重复号码输出号码及其个数
            cout << e.first << " " << e.second << endl;
            flag = true;
        }
        
    }
    if (!flag)
    {
        cout << "No duplicates." << endl;
    }
    
    return 0;
}