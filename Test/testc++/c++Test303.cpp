//滑窗+前缀和
#include <bits/stdc++.h>
//蓝桥杯--字串简写
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e6+10;
int countb[N];//用于记录字符串s中每个位置之前出现字符c2的次数

void Solve(void)
{
  int k;
  cin >> k;
  string s;
  char c1, c2;
  cin >> s >> c1 >> c2;
  int n = s.size();
  for (int i = 1; i <= n; i++)
  {
    countb[i] = countb[i - 1];//记录的是i之前出现c2的次数
    if (s[i - 1] == c2) countb[i]++;
  }
  ll cnt = 0;
  for (int i = 0, j = -1; i < n; i++)//快慢指针，i为慢指针，j为快指针
  {
    if(s[i]==c1){
      if(j==-1) j = i + 1;
      while (j<n)
      {
        if (s[j] == c2 && j - i + 1 >= k) break;
        j++;
      }
      cnt += countb[n] - countb[j];//表示滑窗内字符等于c2的次数
    }
  }
  cout << cnt << endl;
}

/*
//前缀和解法
void Solve(void)
{
  int k;
  cin >> k;
  string s;
  char c1, c2;
  cin >> s >> c1 >> c2;
  int n = s.size();
  for(int i=0;i<n;i++)
  {
    countb[i+1]=countb[i];
    if(s[i]==c1) countb[i+1]=countb[i]+1;//countb[i]表示从s[0]到s[i-1]中等于c1的字符的个数
  }
  ll ans=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]==c2){//判断是否存在以当前字符s[i]为终点且长度为k的子串
      if(i+1-k+1>=1) ans+=countb[i+1-k+1];
    }
  }
  cout<<ans<<endl;
}
*/

int main()
{
  Solve();
  return 0;
}
/*
//二分解法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e6+10;

void Solve(void)
{
  int n;
  cin>>n;
  string s;
  char a,b;
  cin>>s>>a>>b;
  ll ans=0;
  vector<int> pca;//用于保存字符串s中字符等于a的位置
  for(int i=0;i<s.length();i++)
  {
  	if(s[i]==a) pca.push_back(i);
  	if(s[i]==b){
  		if(i-n+1<0||!pca.size()) continue;
  		
  		int l=0,r=pca.size()-1;//初始化两个指针l和r，分别指向pca的首尾元素
  		while(l<r)
  		{
  			int mid=l+r+1>>1;
  			if(pca[mid]<=(i-n+1))
  			{
  				l=mid;
			  }
			  else{
				  r=mid-1;
			  }
		  }
		
		if(pca[l]<=(i-n+1)) ans+=(l+1);
	  }
  }
  cout<<ans<<endl;
}

int main()
{
  // 请在此输入您的代码
  int t=1;
  //cin>>t;
  while(t--)
  {
    Solve();
  }
  return 0;
}
*/