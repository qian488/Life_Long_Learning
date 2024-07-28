#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,x;
	cin>>n>>x;
	ll cnt=0;
	for(int a=1;a<=x;a++){
		for(int b=1;b<=x-a;b++){
			int c=(n-a*b)/(a+b);
			if(c<=0) break;
			if(a+b+c>x) c=x-a-b;
			if(c>0) cnt+=c;
		}
	}
	cout<<cnt<<endl;
    }
    return 0;
}
