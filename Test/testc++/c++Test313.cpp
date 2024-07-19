#include<bits/stdc++.h>
//蓝桥--蛇形填数
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;
int a[N];
int main()
{
    int ans = 0;
    
    for (int i = 1; i <= 40; i++)
    {
        a[i]=a[i-1]+i;
        cout<<a[i]<<" ";
    }
    cout << a[40];
    //761
    return 0;
}
/*
//模拟
#include<bits/stdc++.h>
using namespace std;

int mp[200][200], row = 0, col = 0, cnt = 1;

int main() {
    mp[0][0] = 1;
    while(!mp[19][19]) {
        //右移
        mp[row][++col] = ++cnt;
        //左下方
        while(col) {
            mp[++row][--col] = ++cnt;
        }
        //下移
        mp[++row][col] = ++cnt;
        //右上方
        while(row) {
            mp[--row][++col] = ++cnt;
        }
    }
    //for(int i = 0; i < 20; i++) {
    //    for(int j = 0; j < 20; j++) {
    //        cout << mp[i][j] << "  ";
    //    }
    //    cout << endl;
    //}
    cout << mp[19][19];
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int row=1,col=1,flag=1,num=1;
    while(true){
        if(row==1){
            col++;flag=1;num++;
        }
        if(col==1){
            row++;flag=-1;num++;
        }
        row+=flag;col-=flag;num++;
        if(row==20&&col==20) break;
    }
    cout<<num;
    return 0;
}
*/