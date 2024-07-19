class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int i = 0; i <= limit; i++) {
            for (int j = 0; j <= limit; j++) {
                if (i + j > n) {
                    break;
                }
                if (n - i - j <= limit) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
    int c2(int n) {
        return n > 1 ? n * (n - 1) / 2 : 0;
    }
public:
    int distributeCandies(int n, int limit) {
        return c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) - c2(n - 3 * limit - 1);
    }
};