#include<iostream>
#include<string>
#include<queue>
using namespace std;
//办事大厅排队
queue<string> q;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s=="in")
        {
            string t;
            cin >> t;
            q.push(t);
        }
        else if (s=="out")
        {
            q.pop();
        }
        else if (s=="q")
        {
            if (q.size()>0)
            {
                cout << q.front() << endl;
            }
            else
            {
                cout << "NULL" << endl;
            }
            
        }
        
        
    }
    
    return 0;
}