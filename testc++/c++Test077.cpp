#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include <string>
using namespace std;
//对称排序

int main()
{
    int caseNum = 1;
    int n;
    cin >> n;
    
    while (n != 0) 
    {
        vector<string> a, b;
        for (int i = 1; i <= n; i++)
        {
            string t;
            if (i%2!=0)
            {
                cin >> t;
                a.push_back(t);
            }
            else
            {
                cin >> t;
                b.push_back(t);
            }
            
        }
        

        cout << "SET " << caseNum++ << endl;

        int lena = a.size(), lenb = b.size();
        for (int i = 0; i < lena; i++)
        {
            cout << a[i] << "\n";
        }
        for (int i = lenb-1; i >= 0; i--)
        {
            cout << b[i] << "\n";
        }
        

        cin >> n;
    }

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
queue<string>q;
stack<string>s;
string temp;
int n,num=1;
while (1) {
cin>>n;
if(!n) break;
cout<<"SET "<<num++<<endl;
while (n) {
cin>>temp;
q.push(temp);
n--;
if (n) {
cin>>temp;
s.push(temp);
n--;
}
}
while (!q.empty()) {
cout<<q.front()<<endl;
q.pop();
}
while (!s.empty()) {
cout<<s.top()<<endl;
s.pop();
}
}
}
*/