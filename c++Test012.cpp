#include<iostream>
using namespace std;
int main()
{
    int n,j,s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        j*=i;
        s+=j;
    }
    cout << j << endl;
    cout<<s;
    return 0;
}