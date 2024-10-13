class Solution {
public:
    int twoEggDrop(int n) {
        int cnt = 0;
        for(int i=1;n>0;i++){
            n-=i;
            cnt++;
        } 
        return cnt;
    }
};