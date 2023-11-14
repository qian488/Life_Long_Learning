#include<iostream>

using namespace std;
//最厉害的学生
#define N 10001
struct stu
{
    string s;
    int a;
    int b;
    int c;
    int sum;
}s1,s2;

int main()
{
    int n;
    cin >> n;
    s1.sum = -1;
    for (int i = 0; i < n;i++)
    {
        cin >> s2.s >> s2.a >> s2.b >> s2.c;
        s2.sum = s2.a + s2.b + s2.c;
        if (s1.sum<s2.sum)
        {
            s1 = s2;
        }
        
    }
    cout << s1.s << " " << s1.a << " " << s1.b << " " << s1.c;
    return 0;
}