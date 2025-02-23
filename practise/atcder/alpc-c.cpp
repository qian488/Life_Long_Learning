#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

constexpr long long MOD = 998244353;
constexpr long long INV_2 = 499122177;  // 2的逆元
constexpr long long INV_6 = 166374059;  // 6的逆元

struct Floor_sum {
    long long f, g, h;  // 三个函数值

    Floor_sum(long long f = 0, long long g = 0, long long h = 0) : f(f), g(g), h(h) {}

    // 重载加法运算符，方便合并结果
    Floor_sum operator+(const Floor_sum& other) const {
        return Floor_sum((f + other.f), (g + other.g), (h + other.h));
    }
};

// 单独封装 f 的计算逻辑
long long calculate_f(long long n, long long a, long long b, long long c, bool is_mod = true) {
    if (a == 0) {
        return is_mod ? ((b / c) * (n + 1) % MOD) : ((b / c) * (n + 1));
    }
    if (a >= c || b >= c) {
        long long ac = a / c, bc = b / c;
        long long base_f = is_mod ? ((ac * n % MOD * (n + 1) % MOD * INV_2 + bc * (n + 1)) % MOD) : (ac * n * (n + 1) / 2 + bc * (n + 1));
        return is_mod ? ((base_f + calculate_f(n, a % c, b % c, c, true)) % MOD) : (base_f + calculate_f(n, a % c, b % c, c, false));
    }
    long long m = (a * n + b) / c;
    return is_mod ? ((n * m % MOD - calculate_f(m - 1, c, c - b - 1, a, true) + MOD) % MOD) : (n * m - calculate_f(m - 1, c, c - b - 1, a, false));
}

// 封装 g 和 h 的计算逻辑，依赖 f 的结果
Floor_sum calculate_gh(long long n, long long a, long long b, long long c, long long f, bool is_mod = true) {
    if (a == 0) {
        long long bc = b / c;
        return is_mod ? Floor_sum(bc * n % MOD * (n + 1) % MOD * INV_2 % MOD, bc * bc % MOD * (n + 1) % MOD) : Floor_sum(bc * n * (n + 1) / 2, bc * bc * (n + 1));
    }
    if (a >= c || b >= c) {
        long long ac = a / c, bc = b / c;
        Floor_sum base(is_mod ? (ac * n % MOD * (n + 1) % MOD * (2 * n + 1) % MOD * INV_6 % MOD + bc * n % MOD * (n + 1) % MOD * INV_2 % MOD) : (ac * n * (n + 1) * (2 * n + 1) / 6 + bc * n * (n + 1) / 2),
                       is_mod ? (ac * ac % MOD * n % MOD * (n + 1) % MOD * (2 * n + 1) % MOD * INV_6 % MOD + bc * bc % MOD * (n + 1) % MOD + ac * bc % MOD * n % MOD * (n + 1) % MOD) : (ac * ac * n * (n + 1) * (2 * n + 1) / 6 + bc * bc * (n + 1) + ac * bc * n * (n + 1)));
        Floor_sum recursive = calculate_gh(n, a % c, b % c, c, f, is_mod);
        return is_mod ? Floor_sum((base.g + recursive.g) % MOD, (base.h + recursive.h + 2 * bc % MOD * recursive.f % MOD + 2 * ac % MOD * recursive.g % MOD) % MOD) : Floor_sum(base.g + recursive.g, base.h + recursive.h + 2 * bc * recursive.f + 2 * ac * recursive.g);
    }
    long long m = (a * n + b) / c;
    Floor_sum recursive = calculate_gh(m - 1, c, c - b - 1, a, f, is_mod);
    return is_mod ? Floor_sum((m * n % MOD * (n + 1) % MOD - recursive.h - recursive.f + MOD) % MOD * INV_2 % MOD,
                              (n * m % MOD * (m + 1) % MOD - 2 * recursive.g - 2 * recursive.f - recursive.f + MOD) % MOD) : Floor_sum((m * n * (n + 1) - recursive.h - recursive.f) / 2,
                                                                                                                               n * m * (m + 1) - 2 * recursive.g - 2 * recursive.f - recursive.f);
}

// 主计算函数，整合 f、g、h 的计算
Floor_sum calculate(long long n, long long a, long long b, long long c, bool is_mod = true) {
    long long f = calculate_f(n, a, b, c, is_mod);
    Floor_sum gh = calculate_gh(n, a, b, c, f, is_mod);
    return Floor_sum(f, gh.g, gh.h);
}

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    Floor_sum result = calculate(n - 1, a, b, m, false);
    cout << result.f << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}