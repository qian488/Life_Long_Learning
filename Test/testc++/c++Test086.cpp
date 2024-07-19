#include <iostream>
using namespace std;
//染色
//sb，直接i*j%2==0

int main() {
    int n,m;
    cin>>n>>m;
    bool win = true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if ((i*j)%2==0)
            {
                win = false;
            }
            
        }
    }
    if(win)
    {
        cout<<"akai"<<endl;
    }
    else
    {
        cout<<"yukari"<<endl;
    }
    return 0;
}
