#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,c,t;
    long long ans = 0;
    cin>>n>>c;

    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        nums.push_back(t+c);
    }

    sort(nums.begin(),nums.end());
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    for(int i=0;i<n;i++)
    {
        int l=0,r=n+1;
        while(l+1<r)
        {
            int mid=l+r>>1;
            if(nums[mid]<=i)
            {
                r=mid;
            }
            else
            {
                l=mid;
            }

        }
        if (nums[l]==nums[i])
        {
            ans++;
        }
        cout << l << " ";
    }
    cout<<ans;
    return 0;
}