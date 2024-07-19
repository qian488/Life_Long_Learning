#include<iostream>
#include<string>
using namespace std;
//日期杯
int count;
int ans;

bool is_y(int y)
{
    return ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0));
}
/*
int check(string num,int y,int m,int d,int k)
{
    num=to_string(y)+to_string(m)+to_string(d);
    ans = 0;
    //cout << "num:" << num << endl;
    for (int i = 0; i < num.size(); i++)
    {
        ans += num[i] - '0';
    }
        if (ans==k)
        {
            count++;
        }
        return count;
}
*/
int numsum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void sol()
{
    int a,b,k;
    cin>>a>>b>>k;
    //string num;
    int y, m, d;
    count = 0;
    int ds[] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int y = a; y <= b; y++)
    {
        if (is_y(y))
        {
            ds[2] = 29;
        }
        else
        {
            ds[2] = 28;
        }
        for (int m = 1; m <= 12; m++)
        {
            for (int d = 1; d <= ds[m]; d++)
            {
                //count=check(num, y, m, d, k);
                if (numsum(y)+numsum(m)+numsum(d)==k)
                {
                    count++;
                }
                
            }
            
            
        }
        
    }

    cout << count << endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        sol();
    }
    
    return 0;
}