#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Capoo's Acronym Zero
//tle
int n, q;
string s;
vector<string> v,ans;
void sol()
{
    string c,st;
    cin >> c;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        st = v[i];
        string str = "";
        int len = st.size();
	    for (int j = 0; j < len; j++)
	    {
		    if (st[j] >= 'A'&&st[j] <= 'Z')
			{
                str+=st[j]; 
            }
	    }
        //cout << str << " ";
        if (c==str)
        {
            ans.push_back(st);
            sum++;
        }
        
    }
    cout << sum << endl;
    if (sum>0)
    {
        for (int i = 0; i < sum; i++)
        {
            cout << ans[i] << endl;
        }
        
    }
    
}
int main()
{
    
    cin >> n >> q;
    
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < q; i++)
    {
        sol();
        ans.clear();
    }
    
    return 0;
}