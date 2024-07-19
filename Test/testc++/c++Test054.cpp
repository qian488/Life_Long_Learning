#include<iostream>

using namespace std;
//评等级
struct stu
{
    int s;
    double a, b, sum, sums;
    double calculatesum()
    {
        sum = a + b;
        return sum;
    }
};

bool check(stu s)
{
    double sum = s.calculatesum();
    if (sum>140&&s.sums>=800)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    stu s1;
    for (int i = 0; i < n; i++)
    {
        cin >> s1.s >> s1.a >> s1.b;
        s1.sums = s1.a * 7 + s1.b * 3;
        if (check(s1))
        {
            cout << "Excellent" << endl;
        }
        else
        {
            cout << "Not excellent" << endl;
        }
        
    }
    return 0;
}