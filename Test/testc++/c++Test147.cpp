#include<iostream>
#include<algorithm>
using namespace std;
//蓝桥小白赛3--聪明的交换策略
const int N=1e5+10;

int main()
{

  int n;
  cin>>n;
  string str;
  cin>>str;

  //利用双指针算法
  int p=0,st1=0;

  //首先计算出将0全部移到右边的交换次数，p始终指向‘1’，通过循环去找字符‘0’，完成交换
  for(int i=0;i<n;i++){
    if(str[i]=='0'){
      st1+=i-p;
      p++;
    }
  }

  p=0;
  int st2=0;
  //其次计算，将1全部移到右边的交换次数，p始终指向‘0’，通过for循环找字符‘0’，完成交换
  for(int i=0;i<n;i++){
    if(str[i]=='1'){
      st2+=i-p;
      p++;
    }
  }

//取一个最小值
  int res=min(st1,st2);

  cout<<res<<endl;
  return 0;
}