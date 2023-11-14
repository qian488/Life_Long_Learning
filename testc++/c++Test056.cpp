#include<iostream>
#include<vector>
using namespace std;
//A*B
vector<int> mul(vector<int> &A,vector<int> &B)
{
    vector<int> C;

    int t = 0;
    for (int j = 0; j < B.size(); j++)
    {
        for (int i = 0; i < A.size()||t; i++)
        {
            
            t += A[i] * B[j];
            C.push_back(t % 10);
            t /= 10;
        }
    }
    
    
    return C;
}
int main()
{
    string a, b;

    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size()-1; i >=0 ; i--)
    {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size()-1; i >=0 ; i--)
    {
        B.push_back(b[i] - '0');
    }

    vector<int> C = mul(A, B);
    for (int i = C.size()-1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }
    
    return 0;
}