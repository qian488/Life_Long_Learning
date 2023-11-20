#include<iostream>
#include<vector>
using namespace std;
//A*B
//大数乘大数要怎么解决呢？
vector<int> mul(vector<int> &A,vector<int> &B)
{
    vector<int> C(A.size()+B.size(),0);

    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            t += A[i] * B[j] + C[i + j];
            C[i + j] = t % 10;
            t /= 10;
        }
        int k = B.size();
        if (t)
        {
            C[i + k] = t % 10;
            t /= 10;
            k++;
        }
        
    }
    while (C[C.size()-1]==0&&C.size()>1)
    {
        C.pop_back();
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