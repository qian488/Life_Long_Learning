#include<iostream>
#include<cmath>
#include<map>
#include<string>
using namespace std;
//旗鼓相当的对手
#define N 10001
struct stu
{
    string s;
    int a;
    int b;
    int c;
    int sum;
};
int main()
{
    int n;
    cin >> n;
    stu s[N];
    for (int i = 0; i < n;i++)
    {
        cin >> s[i].s >> s[i].a >> s[i].b >> s[i].c;
        s[i].sum = s[i].a + s[i].b + s[i].c;
    }
    //map<string, string> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (abs(s[i].a-s[j].a)<=5&&abs(s[i].b-s[j].b)<=5&&abs(s[i].c-s[j].c)<=5&&abs(s[i].sum-s[j].sum)<=10)
            {
                //ans[s[i].s] = s[j].s;
                cout << s[i].s << " " << s[j].s << endl;
            }
            
        }
        
    }
/*
    for (const auto& pair : ans)
    {
        cout << pair.first << " " << pair.second << endl;
    }
*/
//map不能过的原因：key值唯一，不能重复
/*
    for (auto it = ans.begin(); it != ans.end(); it++) 
    {
        cout << it->first << " " << it->second << endl;
    }
*/
/*
    for (int i = 0; i < n; i++)
    {
        
        cout << s[i].s << s[i].a << s[i].b << s[i].c << s[i].sum << endl;
    }
*/   
    return 0;
}