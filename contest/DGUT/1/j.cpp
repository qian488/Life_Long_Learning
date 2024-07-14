#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD 1000000007

struct M{ //定义矩阵
    ll a[5][5]={0};
    
    M operator * (const M &other) const {
        M temp;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                for (int k = 0; k < 5; k++){
                    temp.a[i][j] += a[i][k] * other.a[k][j];
                    temp.a[i][j]%=MOD;
                }
            }
        }
        return temp;
    }
 };

int a[100005] = {0};
string s;

M qpw(M x) {
    M res;
    res.a[0][0] = 1, res.a[1][1] = 1, res.a[2][2] = 1, res.a[3][3] = 1, res.a[4][4] = 1;
    for (int i = s.size() - 1; i >= 0; i--){
        for (int j = 0; j < s[i] - '0'; j++){
            res = res * x;
        }
        x = x * x * x * x * x * x * x * x * x * x; // 按十进制一位一位求
    }
    return res;
}
int main(){
    cin >> s;
    M x, y;
    x.a[0][0] = 1, x.a[0][4] = 1, x.a[1][0] = 1, x.a[2][1] = 1, x.a[3][2] = 1, x.a[4][3] = 1;
    y.a[0][0] = 1;
    x = qpw(x);
    y = x * y;
    cout << y.a[0][0];
    return 0;
 }