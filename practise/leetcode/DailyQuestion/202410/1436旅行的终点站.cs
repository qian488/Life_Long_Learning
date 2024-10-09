public class Solution {
    public string DestCity(IList<IList<string>> paths) {
        HashSet<string> sa = new HashSet<string>();
        foreach (var p in paths){
            sa.Add(p[0]);
        }
        foreach (var p in paths){
            if(!sa.Contains(p[1])){
                return p[1];
            }
        }
        return "";
    }
}