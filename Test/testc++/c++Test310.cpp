#include<bits/stdc++.h>
//蓝桥--字串排序
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

int main()
{
    int n;
    cin >> n;
    
    return 0;
}
/*
//正解：贪心构造
#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,tmp = 1,sum3 = 0;
string s = "";
map <int,int> mp;
map <int,int> mp2;
bool check (int x){
	int tmp = ((x - (x / 26 + 1)) * (x / 26 + 1) * (x % 26) + (x - x / 26) * (x / 26) * (26 - x % 26) ) >> 1;
	return tmp < n;	
}
bool check2 (int x,int len){
	mp2.clear();
	int sum1 = 0,sum2 = 0;
	for (int i = 26; i >= x + 1; --i) sum1 += mp[i];
	++mp[x];
	for (int i = 1; i <= len; ++i){
		int maxn = -1,pos,sum = 0;
		for (int j = 26; j >= 1; --j){
			if (i - 1 - mp2[j] + sum > maxn){
				maxn = i - 1 - mp2[j] + sum;
				pos = j;
			} 
			sum += mp[j];
		}
		sum2 += maxn;
		++mp2[pos];
	}
	int tmp = sum1 + sum2 + sum3;
	if (tmp >= n){
		sum3 += sum1;
		return 1;
	}else{
		--mp[x];
		return 0;
	}
}
signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	while (check(tmp)) ++tmp;
//	cout << tmp << '\n';
	for (int len = 1; len <= tmp; ++len){
		for (int i = 1; i <= 26; ++i){
			if (check2(i,tmp - len)){
				char x = char (i + 96);
				s += x;
				break;
			}
		}
	}
	cout << s << '\n';
	return 0;
}
*/