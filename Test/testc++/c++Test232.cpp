#include<iostream>

using namespace std;
//AtCoder Beginner Contest 343_B.Adjacency Matrix
typedef long long ll;
const int N = 101;
int A[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> A[i][j];
            if(A[i][j]==1)cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}