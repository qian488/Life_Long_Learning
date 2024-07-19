#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//金鱼的饭店
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(),::tolower);
        if(s=="fandian")
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}