#include<iostream>
#include<string>
using namespace std;
//学号解析
int main()
{
    string s;
    cin>>s;
    cout<<"year:"<<s.substr(0,4)<<"\n";
    cout<<"department:"<<s.substr(4,2)<<"\n";
    cout<<"class:"<<s.substr(6,2)<<"\n";
    return 0;
}