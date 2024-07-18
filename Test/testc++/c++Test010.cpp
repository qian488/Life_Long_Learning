#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,min,max;
    double s;
    cin>>a>>b>>c;

	max=a,min=a;
	if(b>c)
	{
		if(b>max)  max=b;
		if(c<min)  min=c;
	}
    else 
	{
		if(c>max)  max=c;
		if(b<min)   min=b;
	}
	for(int i=min;i>0;i--)
	{
		if(max%i==0&&min%i==0)
		{
			min/=i;
			max/=i;
		}
	}
    cout<<min<<"/"<<max;
    return 0;
}