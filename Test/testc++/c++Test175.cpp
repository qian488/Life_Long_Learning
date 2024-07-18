#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//牛客周赛 Round 29--小红的中位数
//暴力模拟会tle
//优化->记录每次删去的是什么
//还是超时
typedef long double ld;
const int N = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ld> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int it = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        a.erase(a.begin()+it);
        int l = a.size() >> 1, r = a.size() >> 1;
        if(a.size()%2==0) 
        {
            l--;
        }
        ld ans = (a[l] + a[r]) * 1.0 / 2;
        //printf("%.1llf\n", ans);
        cout << fixed << setprecision(1) << ans << endl;
        a.insert(a.begin() + it, b[i]);
    }
     
    return 0;
}
//一个题解的思路,分别求中位数的整数和小数部分
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<int> a(n), ans(n);
  for (int& ai : a) { cin >> ai; }
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i += 1) { p.emplace_back(a[i], i); }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i += 1) {
    if (n % 2) {
      int j = n / 2 - 1, k = n / 2;
      if (j >= i) { j += 1; }
      if (k >= i) { k += 1; }
      ans[p[i].second] = p[j].first + p[k].first;
    } else {
      int j = n / 2 - 1;
      if (j >= i) { j += 1; }
      ans[p[i].second] = p[j].first * 2;
    }
  }
  for (int x : ans) { cout << x / 2 << "." << (x % 2 * 5) << "\n"; }
}
*/
//另一个题解的思路，暴力枚举中位数的情况
/*
#include<bits/stdc++.h>
using namespace std;
int n;
double a[100010],b[100010];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
        b[i]=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(n%2==0){
            if(b[i]<=a[n/2-1]) printf("%.1f\n",a[n/2]);
            else printf("%.1f\n",a[n/2-1]);
        }else{
            if(b[i]<a[n/2]) printf("%.1f\n",(a[n/2]+a[n/2+1])/2);
            else if(b[i]>a[n/2]) printf("%.1f\n",(a[n/2]+a[n/2-1])/2);
            else if(b[i]==a[n/2]) printf("%.1f\n",(a[n/2-1]+a[n/2+1])/2);
        }
    }
    return 0;
}
*/