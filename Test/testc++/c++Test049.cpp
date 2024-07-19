#include<iostream>
#include<cmath>
using namespace std;
//赦免战俘
/*
一个大佬的妙解
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<(1<<n);j++){
			printf("%d ",(i|j)!=((1<<n)-1)?0:1);}//点睛之笔位运算,但是不太懂
		printf("\n");}
	return 0;}
*/
int a[2048][2048];
int p;
void sol(int x,int y,int p)
{
    if (p==1)
    {
        return;
    }

    for (int i = x; i < x+(p/2); i++)
    {
        for (int j = y; j < y+(p/2); j++)
        {
            a[i][j] = 0;
        }
        
    }

    sol(x + (p / 2), y, p / 2);
    sol(x, y + (p / 2), p / 2);
    sol(x + (p / 2), y + (p / 2), p / 2);
}
int main()
{
    int n;
    cin >> n;
    p = pow(2, n);
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            a[i][j] = 1;
        }
        
    }
    
    sol(1, 1, p);
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}