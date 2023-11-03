#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int n,m,t;
    cin>>n>>m;

    vector<int> nums;

    for (int i = 0; i < n;i++)
    {
        cin>>t;
        nums.push_back(t);
    }

    
    while(m--)
    {
        cin>>t;
        int l=0,r=n-1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= t)
            {
                r = mid;
            }
            else 
            {
                l=mid + 1;
            }

            
        }

        if(nums[l]!=t)
            {
                cout<<"-1 ";
            }
            else
            {
                
                cout<<l + 1<<" ";
            }
    }


    return 0;
}