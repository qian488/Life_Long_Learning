#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,c=0,j;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        j = n;
        while (j>i)
        {
            c++;
            if (c<10)
            {
                cout << setw(1)<<'0' << c;
            }
            else
            {
                cout << c;
            }
            j--;
        }
        cout << endl;
    }
    return 0;
}