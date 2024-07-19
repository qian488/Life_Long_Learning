#include<bits/stdc++.h>
//蓝桥--跑步锻炼
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

int main()
{
    int ans = 0;
    int cnt=4;
    for (int i = 2000; i <= 2020; i++)
    {
        for(int j=1;j<=12;j++)
        {
        	for(int k=1;k<=return_days(i,j);k++)
        	{
        		ans++;
                if(cnt==8) cnt = 1;
                if(cnt==1||k==1) ans++;
                cnt++;
                if (i == 2020 && j == 10 && k == 1)
                {
                    cout << ans << endl;
                    return 0;
                }
            }
		}
    }
    cout << ans;
    //8879
    return 0;
}