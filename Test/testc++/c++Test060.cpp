#include<iostream>
#include<cmath>
using namespace std;
//数论不可能这么简单
int main()
{
    long long N;
    int cnt=0;
    cin>>N;
    for(int a=0;a<100;a++)
    {
        for(int b=0;b<100;b++)
        {
            if(pow(2,a)*pow(3,b)==N)
            {
                cout << "Yes";
                return 0;
            }
            
        }

    }
    cout << "No";
    
    return 0;
}