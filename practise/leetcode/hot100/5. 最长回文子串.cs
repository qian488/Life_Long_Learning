/// <summary>
/// dp动态规划
/// </summary>
public class Solution {
    public string LongestPalindrome(string s) {
        int n =  s.Length;
        if(n<2) return s;

        int maxLen = 1;
        int begin = 0;
        int[,] dp = new int[n,n];

        for(int i=0;i<n;i++) dp[i,i]=1;

        for(int L = 2;L <= n; L++){
            for(int i = 0; i < n; i++){
                int j = L + i - 1;
                if(j>=n) break;

                if(s[i] != s[j]){
                    dp[i,j] = 0;
                }else{
                    if(j - i < 3){
                        dp[i,j] = 1;
                    }else{
                        dp[i,j] = dp[i+1,j-1];
                    }
                }

                if(dp[i,j] == 1 && j - i + 1 > maxLen){
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.Substring(begin,maxLen);
    }
}


// 待补充
// 中心扩展法



// 马拉车算法