#include<iostream>
#include<algorithm>
using namespace std;
//二分边界
int main()
{
    int n, target,ans1,ans2;
    cin >> n >> target;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    /*
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    */
    int l = 0, r = n + 1;
    while (l+1<r)
    {
        int mid = l + r >> 1;
        if (nums[mid]>=target)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
        if (nums[r]==target)
        {
            ans1 = r;
        }
        else
        {
            ans1 = -1;
        }
        
    }
    if (ans1!=-1)
    {
        l = ans1, r = n + 1;
        while (l+1<r)
        {
            int mid = l + r >> 1;
            if (nums[mid]<=target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
            if (nums[l]==target)
            {
                ans2 = l;
            }
            
        }
        cout << "[" << ans1 << ", " << ans2 << "]" << endl;
    }
    else
    {
        cout << "[]" << endl;
    }
    
    return 0;
}