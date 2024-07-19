#include<iostream>

using namespace std;
//牛客周赛 Round 29--小红大战小紫
//模拟
typedef long long ll;

int main()
{
    ll a,b;
    cin >> a >> b;
    if (a>b)
    {
        cout << "kou" << endl;
    }
    else if(a==b)
    {
        cout << "draw" << endl;
    }
    else
    {
        cout << "yukari" << endl;
    }
    return 0;
}