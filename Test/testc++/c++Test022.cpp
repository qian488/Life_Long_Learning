#include<iostream>
using namespace std;
int main()
{
    int T,t,k=0;
    char a[201],b[4];
    cin >> T;
    t = T;
    while (T)
    {
        for (int i = 0; i < 4; i++)
        {
            k++;
            cin >> a[k];
        }
        T--;
    }
    
    for (int i = 1; i <= t*4; i+=4)
    {
        if (a[i]==a[i+1]&&a[i+2]==a[i+3]&&a[i+1]==a[i+2])
        {
            cout << "No\n";
        }
        else if(a[i]==a[i+1]&&a[i+1]==a[i+2])
        {
            cout << "Yes\n";
        }
        else if ((a[i]==a[i+1]&&a[i]==a[i+3]))
        {
            cout << "Yes\n";
        }
        else if ((a[i+1]==a[i+2]&&a[i+2]==a[i+3]))
        {
            cout << "Yes\n";
        }
        else if(a[i]==a[i+2]&&a[i]==a[i+3])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        
    }
    return 0;
}