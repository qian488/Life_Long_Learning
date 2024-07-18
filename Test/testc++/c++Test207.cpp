#include <iostream>
#include <vector>
using namespace std;
//think-cell Round 1 B	Permutation Printing
int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        for (int i = 0; i < n;i++)
        {
            if (i%2==1)
            {
                cout << (i + 1) / 2 << " ";
            }
            else
            {
                cout << n - i / 2 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}