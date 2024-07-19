#include<iostream>
using namespace std;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    int temp;
    if (x > y) 
    {
        temp = x;
        x = y;
        y = temp;
    }

    if (y > z) 
    {
        temp = y;
        y = z;
        z = temp;

        if (x > y) 
        {
            temp = x;
            x = y;
            y = temp;
        }
    }
    cout << z << " " << y << " " << x;
}

int main()
{
    solve();
    return 0;
}