#include<bits/stdc++.h>

using namespace std;

int main(){
    double s, a, b;
    cin >> s >> a >> b;
    double x = (2 * a * s) / (3 * a + b);
    double ans = x / a + (s - x) / b;
    printf("%.6lf", ans);
    return 0;
}