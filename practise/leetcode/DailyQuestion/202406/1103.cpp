class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n=num_people;
        vector<int> ans(n,0);
        int cnt=1,kk=0;
        while(candies>0){
            for(int i=0;i<n;i++){
                if(candies-cnt>=0){ 
                    ans[i]+=cnt;
                    candies-=cnt++;
                }else{
                    ans[i]+=candies;
                    return ans;
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans(n);
        for (int i = 1; candies > 0; i++) {
            ans[(i - 1) % n] += min(i, candies);
            candies -= i;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int m = (sqrt(8.0 * candies + 1) - 1) / 2;
        int k = m / n, extra = m % n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = k * (k - 1) / 2 * n + k * (i + 1) + (i < extra ? k * n + i + 1 : 0);
        }
        ans[extra] += candies - m * (m + 1) / 2;
        return ans;
    }
};

