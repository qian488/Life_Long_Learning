
//力扣第 122 场双周赛--100199. 判断一个数组是否可以变为有序
//不会
//力扣的难度还是不能比的 
//方法一
class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        for (int i = 0, n = nums.size(); i < n;) {
            int start = i;
            int ones = __builtin_popcount(nums[i++]);
            while (i < n && __builtin_popcount(nums[i]) == ones) {
                i++;
            }
            sort(nums.begin() + start, nums.begin() + i);
        }
        return ranges::is_sorted(nums);
    }
};
//方法二
class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        int n = nums.size();
        int i = 0, pre_max = 0;
        while (i < n) {
            int mx = nums[i];
            int ones = __builtin_popcount(mx);
            while (i < n && __builtin_popcount(nums[i]) == ones) {
                if (nums[i] < pre_max) {
                    return false;
                }
                mx = max(mx, nums[i++]);
            }
            pre_max = mx;
        }
        return true;
    }
};
/*分组循环模板
n = len(nums)
i = 0
while i < n:
    start = i
    while i < n and ...:
        i += 1
    # 从 start 到 i-1 是一组
    # 下一组从 i 开始，无需 i += 1
*/

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-if-array-can-be-sorted/solutions/2613051/jiao-ni-yi-ci-xing-ba-dai-ma-xie-dui-on-j3nik/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。