#include<iostream>

using namespace std;

//求区间和

const int N = 100010;

int main()
{
	int n,m;
	cin>>n;
	int a[N],b[N];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	
	cin>>m;
	while (m--)
	{
		int l,r;
		cin >> l >> r;
		cout << b[r] - b[l - 1] << endl;
	}
	
	

	return 0;
}