#include<bits/stdc++.h>
//蓝桥--回文日期
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
    if(a==h&&b==g&&c==f&&d==e) return true;
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
/*
//逆向思维
#include<bits/stdc++.h>
using namespace std;
//预处理月份对应天数
int a[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
  int n,m;
  cin>>n>>m;
  int ans=0;
//根据月份和天数直接构造回文年份，看是是否在题目要求范围内
  for(int i=1;i<=12;i++){
    for(int j=1;j<=a[i];j++){
//年份
      int y=j%10*1000+(j/10)*100+i%10*10+i/10;
//年份+月份+天数组成的回文串
      int sum=y*10000+i*100+j;
      if(sum>m||sum<n) continue;
      else ans++;
    }
  }
  cout<<ans;
  return 0;
}
*/