#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//一日之计在于晨呐
bool check()
{
    string s;
    cin>>s;
    int hh = stoi(s.substr(0, s.find(':')));
    int mm = stoi(s.substr(s.find(':') + 1));
    //cout<<"hh:"<<hh<<"mm:"<<mm<<endl;
    if (hh==8&&mm==0)
    {
        return true;
    }
    else if(hh>=8)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int T;
    cin>>T;
    for(int i =0;i<T;i++)
    {
        if(check())
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