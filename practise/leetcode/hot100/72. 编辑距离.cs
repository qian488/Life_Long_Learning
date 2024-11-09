public class Solution {
    public int MinDistance(string s, string t) {
        int n = s.Length, m = t.Length;
        if(n * m == 0) return n + m;

        int[,] dp = new int[n, m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i, j] = -1;
            }
        }

        int Dfs(int i, int j) {
            if(i < 0) return j + 1;
            if(j < 0) return i + 1;

            if (dp[i, j] != -1) {
                return dp[i, j]; 
            }

            if (s[i] == t[j]) {
                dp[i, j] = Dfs(i - 1, j - 1);
            } else {
                dp[i, j] = Math.Min(Math.Min(Dfs(i - 1, j), Dfs(i, j - 1)), Dfs(i - 1, j - 1)) + 1;
            }

            return dp[i, j];
        }

        return Dfs(n - 1, m - 1);
    }
}
