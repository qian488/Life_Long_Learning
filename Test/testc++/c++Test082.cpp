#include <iostream>
using namespace std;
//压缩矩阵
int main()
{
  long long n, q, c, r, x;//不开ll会只过部分数据
  cin >> n >> q;
  while (q--)
  {
    cin >> x;
    x++;//补上虚拟的第一个点位，实现除三分行数
    c = x / 3 + 1;
    r = x % 3 - 1;//找到偏移的值，确定是左中右
    cout << c << " " << c+r << endl;
  }
  
  return 0;
}
/*
虽然我也不知道为啥过不了
哦，二重循环，会超时
int main()
{
  int n,q,x;
  cin>>n>>q;
  for(int i=0;i<q;i++)
  {
    cin>>x;
    for(int j=1;j<=n;j++)
    {
        if(x==3*j-3)
        {
            cout<<j<<" "<<j<<endl;
        }
        else if(x==3*j-4)
        {
            cout<<j<<" "<<j-1<<endl;
        }
        else if(x==3*j-2)
        {
            cout<<j<<" "<<j+1<<endl;
        }
    }
  }

  return 0;
}
*/