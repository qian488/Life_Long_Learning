#include<iostream>
#include<string>
using namespace std;
//比较两个整数的大小
int main()
{
    string a, b;
    while (cin>>a>>b)
    {
        if (a.length()>b.length())
        {
            cout << "Greater" << endl;
        }
        else if (a.length()<b.length())
        {
            cout << "Less" << endl;
        }
        else
        {
            if (a>b)
            {
                cout << "Greater" << endl;
            }
            else if (a<b)
            {
                cout << "Less" << endl;
            }
            else
            {
                cout << "Equal" << endl;
            }
            
        }
        
        
    }

    return 0;
}