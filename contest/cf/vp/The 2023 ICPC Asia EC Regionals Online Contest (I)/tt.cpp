#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define double long double
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int x1,y1,x2,y2,x3,y3,x4,y4;cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        double cx1=(x1+x2)/2.0;
        double cy1=(y1+y2)/2.0;
        double cx2=(x3+x4)/2.0;
        double cy2=(y3+y4)/2.0;
        double r=sqrtl((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3))/2;
        cout<<fixed<<setprecision(16)<<fabs(cx1-cx2)+fabs(cy1-cy2)-sqrt(2)*r<<'\n';
        }
    return 0;
}