#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//pta并查集专场--谁问你了
const int N = 1000010;
int p[N], size[N];
int n, m;
int cnt;
void init()
{
    cnt = n;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        size[i] = 1;
    }
    
}
int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
void add(int a,int b)
{
    int x = find(a);
    int y = find(b);
    if (x!=y)
    {
        p[x] = y;
        size[y] += size[x];
        size[x] = 0;
        cnt--;
    }
    
}
int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        add(a, b);
    }
    cout << cnt << endl;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (p[i]==i&&size[i]>0)
        {
            ans.push_back(size[i]);
        }
        
    }
    sort(ans.begin(), ans.end());
    for(auto e:ans)
    {
        cout << e << " ";
    }
    return 0;
}