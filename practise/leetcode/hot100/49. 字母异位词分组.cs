/// <summary>
/// 题目是要将每个字符串的所有可能情况排列返回
/// 使用字典 Dictionary<string, List<string>>
/// string 作为key，是已排好序的字符串
/// List<string> 是有key的字母组成的字符串集
/// 思路很明显就是遍历数组，将字符串排序作为key存入字典，如果在字典中，加入List<string>，不在就新建一个再加入
/// 最后返回由List<string>组成的数组
/// </summary>
public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        Dictionary<string, List<string>> map = new Dictionary<string, List<string>>();

        foreach (var str in strs) {
            char[] charArray = str.ToCharArray();
            Array.Sort(charArray);
            string sortedStr = new string(charArray);
            
            if (!map.ContainsKey(sortedStr)) {
                map[sortedStr] = new List<string>();
            }

            map[sortedStr].Add(str);
        }
        
        return map.Values.ToList<IList<string>>();
    }
}