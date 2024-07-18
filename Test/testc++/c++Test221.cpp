#include<iostream>

using namespace std;
//HUAWEI Programming Contest 2024（AtCoder Beginner Contest 342_A.Yay!
int main()
{
  string s;
  cin>>s;
  char a = s[0];
  char b = s[1];
  for(int i=2;i<s.size();i++)
  {
    if(a==b)
    {
        if(s[i]!=a) 
        {
            cout << i + 1;
            return 0;
        }
    }
    else
    {
        if(s[2]==a)
        {
            cout << 2;
            return 0;
        }
        else
        {
            cout << 1;
            return 0;
        }
    }
  }
  
  return 0;
}