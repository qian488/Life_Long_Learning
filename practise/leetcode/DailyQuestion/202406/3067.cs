public class Solution {
    public int[] CountPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.Length + 1;
        List<(int, int)>[] g = new List<(int, int)>[n];
        for(int i=0;i<n;i++){
            g[i] = new List<(int, int)>();
        }
        foreach(int[] e in edges){
            int x = e[0], y = e[1], w = e[2];
            g[x].Add((y, w));
            g[y].Add((x, w));
        }

        int Dfs(int x,int fa,int sum){
            int cnt = sum % signalSpeed == 0 ? 1 : 0;
            foreach((int y,int w) in g[x]){
                if(y!=fa){
                    cnt += Dfs(y, x, sum + w);
                }
            }
            return cnt;
        }

        int[] ans = new int[n];
        for(int i=0;i<n;i++){
            int sum = 0;
            foreach((int y,int w) in g[i]){
                int cnt = Dfs(y, i, w);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
        return ans;
    }
}