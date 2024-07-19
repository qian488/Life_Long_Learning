#include<iostream>
#include<stack>
using namespace std;
//括号匹配
//stack
bool check(string str)
{
    stack<char> s;
    for(char c:str)
    {
        if (c=='('||c=='['||c=='{')
        {
            s.push(c);
        }
        else if (c==')'||c==']'||c=='}')
        {
            if (s.empty())
            {
                return false;
            }
            
            char top = s.top();
            
            if ((c==')'&&top=='(')||(c==']'&&top=='[')||(c=='}'&&top=='{'))
            {
                s.pop();
            }
            
        }
        
        
    }
    return s.empty();
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string t;
        cin >> t;
        if (check(t))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        /*
        stack<char> clear;
        s = clear;
        */

        //s = stack<char>();

        /*
        while (!s.empty())
        {
            s.pop();
        }
        */
    }
    
    return 0;
}