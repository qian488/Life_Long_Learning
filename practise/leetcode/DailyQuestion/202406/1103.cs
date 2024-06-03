public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        for(int i=1;candies>0; i++){
            ans[(i - 1) % num_people] += Math.Min(i, candies);
            candies -= i;
        }
        return ans;
    }
}

public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int m = (int)((Math.Sqrt(8.0 * candies + 1) - 1) / 2);
        int k = m / num_people, extra = m % num_people;
        for(int i=0;i<num_people; i++){
            ans[i] = k * (k - 1) / 2 * num_people + k * (i + 1) + (i < extra ? k * num_people + i + 1 : 0);
        }
        ans[extra] += candies - m * (m + 1) / 2;
        return ans;
    }
}