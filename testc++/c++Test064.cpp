#include<iostream>
#include<iomanip>
using namespace std;
//计算平均学分绩点
int main()
{
    int n;
    cin >> n;
    double sum = 0, sumf = 0,GPA;
    double a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        sumf += a[i] * b[i];
        sum += a[i];
    }
    GPA = sumf / sum;
    cout << fixed << setprecision(6) << GPA << endl;
    return 0;
}