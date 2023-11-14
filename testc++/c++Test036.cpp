#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool check(vector<int> v,int mid,int K)
{
    int y = K, j = 0;
    for (int i = 0; i < v.size();i++)
    {
        if (y<0)
        {
            break;
        }
        
        if(v[i]-j<mid)
        {
            j = v[i];
        }
        else
        {
            j += mid;
            i--;
            y--;
        }
    }
        return y >= 0;
}

int main() 
{
    int L, N, K;
    cin >> L >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    v.push_back(L);

    int l=-1, r=L+1;
    while(l+1<r)
    {
        int mid = l + r >> 1;
        if(check(v,mid,K))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l;
    return 0;
}