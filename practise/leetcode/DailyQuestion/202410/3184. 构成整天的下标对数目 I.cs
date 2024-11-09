/// <summary>
/// 暴力解，枚举两数之和
/// </summary>
public class Solution {
    public int CountCompleteDayPairs(int[] hours) {
        int ans = 0;
        int n = hours.Length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((hours[i]+hours[j])%24==0) ans++;
            }
        }
        return ans;
    }
}
/// <summary>
/// 和两数之和的优化思路一样，用哈希表或者数组预存信息
/// 一般地，对于 hours[i]，需要知道左边有多少个模 24 是 24−hours[i]mod24 的数。
/// 特别地，如果 hours[i] 模 24 是 0，那么需要知道左边有多少个模 24 也是 0 的数。
/// 这两种情况可以合并为：累加左边(24−hours[i]mod24)mod24的出现次数。
/// 代码实现时，用一个长为 24 的数组 cnt 维护 hours[i]mod24 的出现次数。
/// </summary>
public class Solution {
    public int CountCompleteDayPairs(int[] hours) {
        const int N = 24;
        int ans = 0;
        int[] cnt = new int[N];
        foreach(int e in hours){
            ans += cnt[(N-e%N)%N];
            cnt[e%N]++;
        }
        return ans;
    }
}