#include<bits/stdc++.h>

using namespace std;

const int N = 10005;
int a[N];

int main(){
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int kk = i;
        for (int j = 2; j <= i; j++) {
            while (kk%j==0){
                a[j]++;
                kk /= j;
            } 
        }
    }

    for (int i = 1; i <= 10000;i++){
        if(a[i]!=0) cout << i << " " << a[i] << endl;
    }

    return 0;
}