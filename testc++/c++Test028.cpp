#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> lines;
vector<int> counts(26,0);

int main()
{
    //getline读入vector存
    string line;
    for(int i=0;i<4;i++)
    {
        getline(cin,line);
        lines.push_back(line);
    }

    //给每个字母出现次数计数
    for(const string &line:lines)
    {
        for(char c:line)
        {
            if(isalpha(c))
            {
                counts[c - 'A']++;
            }
        }
    }

    //找到出现最多次的次数
    int max = *max_element(counts.begin(), counts.end());
    for (int i = max; i > 0;i--)//最多次数控制行数
    {
        for (int j = 0; j < 26;j++)//每行有26个字母的位置
        {
            if(counts[j]>=i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    //输出最后的字母
    for (char c = 'A'; c <= 'Z';c++)
    {
        cout << c << " ";
    }

    cout << endl;
    //调试过程，判断读入是否正确
    for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}