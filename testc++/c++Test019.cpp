#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    float ans;
    cin >> n;
    ans = (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
    cout << fixed<< setprecision(2) << ans;
    return 0;
}