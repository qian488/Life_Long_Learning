class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> dis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, n);
        while (true) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (x <= 1) {
                return dx + x;
            }
            if (dx > dis[x]) {
                continue;
            }
            for (int d = 2; d <= 3; d++) {
                int y = x / d;
                int dy = dx + x % d + 1;
                if (!dis.contains(y) || dy < dis[y]) {
                    dis[y] = dy;
                    pq.emplace(dy, y);
                }
            }
        }
    }
};