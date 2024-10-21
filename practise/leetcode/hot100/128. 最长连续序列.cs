/// <summary>
/// 题目是要找最长的连续序列(不要求原本连续)，但是控制复杂度为O(n)
/// 使用 HashSet 快速找到是否存在
/// 遍历数组中的每个元素，尝试找出以该元素为起点的连续序列。
/// 如果某个数的前一个数字 num - 1 不在集合中，则这个数可以作为一个新的连续序列的起点。
/// 对于每一个新的起点，向上扩展这个序列，计算它的长度。
/// </summary>
public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> set = new HashSet<int>(nums);
        int longestStreak = 0;

        foreach (int num in nums) {
            if (!set.Contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (set.Contains(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = Math.Max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}