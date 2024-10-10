#include <bits/stdc++.h>
#include <iostream>  // For std::cout
#include <vector>   // For std::vector
#include <algorithm> // For std::sort
#include <functional> // For std::function (optional, if needed)

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
 
void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        b[i]--;
    }
    
    std::vector<int> inva(n);
    for (int i = 0; i < n; i++) {
        inva[a[i]] = i;
    }
    
    int bad = 0;
    
    std::vector<std::set<int> > pos(n);
    std::map<int, int> f;
    
    auto insert = [&](int i){
        auto [it, suc] = f.emplace(i, b[i]);
        if (!suc) {
            return;
        }
        auto r = std::next(it);
        if (r != f.end()) {
            bad += (inva[r->second] != inva[b[i]] + 1);
        }
        if (it != f.begin()) {
            auto l = std::prev(it);
            bad += (inva[b[i]] != inva[l->second] + 1);
            if (r != f.end()) {
                bad -= (inva[r->second] != inva[l->second] + 1);
            }
        }
    };
    
    auto erase = [&](int i) {
        auto it = f.find(i);
        if (it == f.end()) {
            return;
        }
        auto r = std::next(it);
        if (r != f.end()) {
            bad -= (inva[r->second] != inva[b[i]] + 1);
        }
        if (it != f.begin()) {
            auto l = std::prev(it);
            bad -= (inva[b[i]] != inva[l->second] + 1);
            if (r != f.end()) {
                bad += (inva[r->second] != inva[l->second] + 1);
            }
        }
        f.erase(it);
    };
    
    for (int i = 0; i < m; i++) {
        pos[b[i]].insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (!pos[i].empty()) {
            insert(*pos[i].begin());
        }
    }
    
    auto answer = [&]() {
        if (bad == 0 && f.begin()->second == a[0]) {
            std::cout << "YA\n";
        } else {
            std::cout << "TIDAK\n";
        }
    };
    
    answer();
    
    for (int i = 0; i < q; i++) {
        int s, t;
        std::cin >> s >> t;
        s--;
        t--;
        erase(s);
        pos[b[s]].erase(s);
        if (!pos[b[s]].empty()) {
            insert(*pos[b[s]].begin());
        }
        b[s] = t;
        if (!pos[t].empty()) {
            erase(*pos[t].begin());
        }
        pos[t].insert(s);
        insert(*pos[t].begin());
        
        answer();
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}