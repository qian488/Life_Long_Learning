#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cnta = 0, cntb = 0, cntc = 0, sum = 0;
    for (int i = 0; i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        cnta += a;
        cntb += b;
        cntc += c;
        sum += a + b + c;
    }
    cout << cnta << " " << cntb << " " << cntc << " " << sum << endl;
    return 0;
}