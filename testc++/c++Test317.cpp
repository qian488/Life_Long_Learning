#include<bits/stdc++.h>
//8
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

bool is_leap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int return_days(int year, int month)
{
    int days[] = {31, (int)(is_leap(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

bool check(int date)
{
	int year=date/10000;
    int month=date%10000/100;
    int day=date%100;
    if(month<=0||month>12||day==0)return false;
    if(day>return_days(year,month))return false;
    return true;
}

bool checkhuiwen(int s)
{
	int a=s/10000000;
    int b=(s/1000000)%10;
    int c=(s/100000)%10;
    int d=(s/10000)%10;
    int e=(s/1000)%10;
    int f=(s/100)%10;
    int g=(s/10)%10;
    int h=s%10;
    if(a==h&&b==g&&c==f&&d==e)
    {
        return true;
    }
    
    return false;
}

int main()
{
	ll start,end;
	cin>>start>>end;
	int ys=start/10000;
	int ye=end/10000;
	int ms=start%10000/100;
	int me=end%10000/100;
	int ds=start%100;
	int de=end%100;
	//cout<<ys<<" "<<ms<<" "<<ds<<endl;
	//cout<<ye<<" "<<me<<" "<<de<<endl;
	int ans=0;
	for(ll i=start;i<=end;i++)
	{
		if(check(i)){
			if(checkhuiwen(i)) ans++;
		}
	}
	cout<<ans<<endl;
    return 0;
}