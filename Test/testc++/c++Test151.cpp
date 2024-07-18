#include<iostream>

using namespace std;
//牛客周赛 Round 28--小红的新周赛
const int N=6;
int main()
{
    int sum=0;
    for(int i=0;i<N;i++)
    {
        int t;
        cin>>t;
        sum+=t;
    }
    cout<<sum;
    return 0;
}