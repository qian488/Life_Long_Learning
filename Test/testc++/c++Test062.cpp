#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
//Capoo's Acronym Zero
//tle
//用map解决
map<string, vector<string>> m;
void sol(map<string, vector<string>>& m)
{
    string c;
    cin >> c;
    int num = 0;
    if (m.find(c) != m.end())
    {
        vector<string> &sentences = m[c];
        num = sentences.size();
        cout << num << endl;
        for (const string& ans:sentences)
        {
            cout << ans << endl;
        }
        
    }
    else
    {
        cout << "0" << endl;
    }
    
}
int main()
{
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string str = "";
        for (int j = 0; j < s.size(); j++)
	    {
		    if (s[j] >= 'A'&&s[j] <= 'Z')
			{
                str += s[j];
            }
	    }
        m[str].push_back(s);
    }
    for (int i = 0; i < q; i++)
    {
        sol(m);
    }
    
    return 0;
}
/*
面向GPT编程
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void sol(map<string, vector<string>>& acronyms)
{
    string c;
    cin >> c;
    int sum = 0;
    if (acronyms.find(c) != acronyms.end())
    {
        vector<string>& sentences = acronyms[c];
        sum = sentences.size();
        cout << sum << endl;
        for (const string& sentence : sentences)
        {
            cout << sentence << endl;
        }
    }
    else
    {
        cout << "0" << endl;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    map<string, vector<string>> acronyms;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string acronym = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] >= 'A' && s[j] <= 'Z')
            {
                acronym += s[j];
            }
        }
        acronyms[acronym].push_back(s);
    }

    for (int i = 0; i < q; i++)
    {
        sol(acronyms);
    }

    return 0;
}
*/
//最初tle的代码
/*
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
*/