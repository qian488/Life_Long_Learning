public class Solution {
    public int MaxHeightOfTriangle(int red, int blue) {
        return Math.Max(Solve(red,blue),Solve(blue,red));
    }

    public int Solve(int x,int y){
        int a = 2 * (int)(Math.Sqrt(x)) - 1;
        int b = 2 * (int)((-1+Math.Sqrt(1 + 4 * y)) / 2);
        return Math.Min(a,b) + 1;
    }
}