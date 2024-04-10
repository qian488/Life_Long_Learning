#include<bits/stdc++.h>
//蓝桥--成绩统计
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

int main()
{
	int n;
	cin>>n;
	int a=0,b=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x>=85) b++;
		if(x>=60) a++;
	}
	double tt=a*100*1.0/n;
	double kk=b*100*1.0/n;
	cout<<(int)(tt+0.5)<<"\%"<<endl;
	cout<<(int)(kk+0.5)<<"\%"<<endl;
    return 0;
}