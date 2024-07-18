#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
//非变形词
map<string, int> isM;
vector<string> lines;
vector<string> ans;
string init(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    sort(s.begin(), s.end());
    return s;
}
int main()
{
    string c;
    while ((cin>>c)&&(c!="#"))
    {
        lines.push_back(c);
        string s = init(c);
        isM[s]++;
    }

    for(auto e:lines)
    {
        string s = init(e);
        //cout << "s:" << s << " int:" << (isM[s]) << endl;
        if (isM[s]==1)
        {
            ans.push_back(e);
        }
        
    }

    sort(ans.begin(), ans.end());
    for(auto e:ans)
    {
        cout << e << endl;
    }

    return 0;
}