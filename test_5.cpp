#include <bits/stdc++.h>
using namespace std;
struct jgt
{
  string a;                               //姓名
  int x,y,z;                              //语文成绩x、数学成绩y、英语成绩z
  int b;                                  //总分
};
int main()
{
  int n;
  cin>>n;
  jgt a[n];
  for(int i=0; i<n; i++)
    cin>>a[i].a>>a[i].x>>a[i].y>>a[i].z,  //读入数据
        a[i].b=a[i].x+a[i].y+a[i].z;      //计算总分
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)              //保证两人不重复出现 j=i+1
      if
      (
        (abs(a[i].x-a[j].x)<=5)&&
        (abs(a[i].y-a[j].y)<=5)&&
        (abs(a[i].z-a[j].z)<=5)&&
        (abs(a[i].b-a[j].b)<=10)
      )                                   //判断是否是旗鼓相当的对手
        cout<<a[i].a<<" "<<a[j].a<<"\n";  //是的话输出
  return 0;
}