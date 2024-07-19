public class Solution {
    public int DistributeCandies(int[] candyType) {
        HashSet<int> s = new HashSet<int>(candyType);
        int ans=Math.Min(s.Count(),candyType.Count()/2);
        return ans;
    }
}

public class Solution {
    public int DistributeCandies(int[] candyType) {
        Dictionary<int,int> ctmp=new Dictionary<int,int>();
        foreach(int e in candyType){
            if(ctmp.ContainsKey(e)){
                ctmp[e]++;
            }else{
                ctmp[e]=1;
            }
        }
        int ans=candyType.Count()/2;
        return Math.Min(ans,ctmp.Count());
    }
}