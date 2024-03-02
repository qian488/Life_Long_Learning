#include<iostream>

using namespace std;
//pta贪心专场--book
//过了样例
const int N = 1e5 + 10;
int A[N];
int main()
{
    int n;
    cin >> n;
    int a, b, sum;
    cin >> A[1] >> a >> b >> sum;
    sum -= A[1];
    cout << A[1] << " ";
    for (int i = 2; i <= n;i++)
    {
        int s = A[1];
        if(s+A[i-1]+a<sum)
        {
            A[i] = A[i - 1] + a;
        }
        else
        {
            A[i] = A[i - 1] - b;
        }
        sum -= A[i];
        s += A[i];
        cout << A[i] << " ";
    }
    return 0;
}