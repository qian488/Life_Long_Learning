#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(m+1,0);
    for (int i = 1; i <= m;i++){
        int x;
        cin>>x;
        v[x]++;
    }

    int l = 0, r = 4e5 + 1;
    while (l+1<r)
    {
        int mid = l + r >> 1;
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if(v[i]>=mid){
                sum += mid;
            }else{
                sum += v[i] + (mid - v[i]) / 2;
            }
        }
        if(sum>=m){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}