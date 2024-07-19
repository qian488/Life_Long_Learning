#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
//集合A-B
set<int> A, B, ans;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            A.insert(t);
        }
        for (int i = 0; i < m; i++)
        {
            int t;
            cin >> t;
            B.insert(t);
        }

        for(auto e:A)
        {
            if (B.find(e)==B.end())
            {
                ans.insert(e);
            }
            
        }
        //原来有直接的库函数用
        //set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(ans));//不过只能存在支持push_back的容器中
        if (ans.size()==0)
        {
            cout << "NULL" << endl;
        }
        else
        {
            for (set<int>::iterator it=ans.begin(); it != ans.end(); it++)
            {
                cout << *it << (next(it) == ans.end() ? "\n" : " ");
            }
            
            /*
            for(auto t:ans)
            {
                cout << t << " ";
            }
            cout << endl;
            */
        }
        A.clear();
        B.clear();
        ans.clear();
    }
    
    return 0;
}