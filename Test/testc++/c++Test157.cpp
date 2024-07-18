#include<iostream>

using namespace std;
//牛客小白月赛86--水盐平衡
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a*1.0/b)<(c*1.0/d))
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "S" << endl;
        }
    }
    
    return 0;
}