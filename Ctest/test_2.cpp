#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<random>
#include<time.h>
#include<cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'

vector<int> mids,is,js,cnts;

int check(vector<int> v,int lim) {
    int cnt=1,j=0;
    for(int i=0;i<v.size();i++) {
        if(v[i]-v[j]>lim) {
            j=i;
            cnt++;
        }
		is.push_back(i);
		js.push_back(j);
		cnts.push_back(cnt);
	}
    return cnt;
}

int main() {
 
	ios::sync_with_stdio(0); cout.tie(0);
 
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int l=-1,r=v.size();
    while(l+1<r) {
        int mid=(l+r)/2;
		mids.push_back(mid);
		if(check(v,mid)<=k) {
            r=mid;
        } else {
            l=mid;
        }
    }
    

	cout << "mids:";
	for (vector<int>::iterator it = mids.begin(); it < mids.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "is:";
	for (vector<int>::iterator it = is.begin(); it < is.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "js:";
	for (vector<int>::iterator it = js.begin(); it < js.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "cnts:";
	for (vector<int>::iterator it = cnts.begin(); it < cnts.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout<<r;
	return 0;
}