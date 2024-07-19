#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//think-cell Round 1 A	Maximise The Score
int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) 
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int score = 0;
        for (int i = 0; i < n; i++)
        {
            score += a[i * 2];
        }

        cout << score << endl;
    }

    return 0;
}