#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 10;
const ll INFL = 4e18;

template <ll MOD>
struct ModInt {
    ll value;
    ModInt(ll x = 0) { value = (x >= 0 ? x % MOD : MOD - (-x) % MOD); }
    ModInt operator-() const { return ModInt(-value); }
    ModInt operator+() const { return ModInt(*this); }
    ModInt& operator+=(const ModInt& other) {
        value += other.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& other) {
        value += MOD - other.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt other) {
        value = value * other.value % MOD;
        return *this;
    }
    ModInt& operator/=(ModInt other) {
        (*this) *= other.inv();
        return *this;
    }
    ModInt operator+(const ModInt& other) const { return ModInt(*this) += other; }
    ModInt operator-(const ModInt& other) const { return ModInt(*this) -= other; }
    ModInt operator*(const ModInt& other) const { return ModInt(*this) *= other; }
    ModInt operator/(const ModInt& other) const { return ModInt(*this) /= other; }
    ModInt pow(ll x) const {
        ModInt ret(1), mul(value);
        while (x) {
            if (x & 1) ret *= mul;
            mul *= mul;
            x >>= 1;
        }
        return ret;
    }
    ModInt inv() const { return pow(MOD - 2); }
    bool operator==(const ModInt& other) const { return value == other.value; }
    bool operator!=(const ModInt& other) const { return value != other.value; }
    friend ostream& operator<<(ostream& os, const ModInt& x) { return os << x.value; }
    friend istream& operator>>(istream& is, ModInt& x) {
        ll v;
        is >> v;
        x = ModInt<MOD>(v);
        return is;
    }
    static constexpr ll get_mod() { return MOD; }
};
using Mod998 = ModInt<998244353>;
using Mod107 = ModInt<1000000007>;

vector<Mod998> NTT998(vector<Mod998> a, bool inv = false) {
    int n = a.size(), h = 0;
    while ((1 << h) < n) h++;
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (int k = 0; k < h; k++) j |= (i >> k & 1) << (h - 1 - k);
        if (i < j) swap(a[i], a[j]);
    }

    const vector<Mod998> rt = {1, 998244352, 911660635, 372528824, 929031873, 452798380, 922799308, 781712469, 476477967, 166035806, 258648936, 584193783, 63912897, 350007156, 666702199, 968855178, 629671588, 24514907, 996173970, 363395222, 565042129, 733596141, 267099868, 15311432};
    const vector<Mod998> irt = {1, 998244352, 86583718, 509520358, 337190230, 87557064, 609441965, 135236158, 304459705, 685443576, 381598368, 335559352, 129292727, 358024708, 814576206, 708402881, 283043518, 3707709, 121392023, 704923114, 950391366, 428961804, 382752275, 469870224};

    for (int b = 1, t = 1; b < n; b <<= 1, t++) {
        Mod998 w = 1, base = inv ? irt[t] : rt[t];
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < n; k += b * 2) {
                Mod998 s = a[j + k];
                Mod998 t = a[j + k + b] * w;
                a[j + k] = s + t;
                a[j + k + b] = s - t;
            }
            w *= base;
        }
    }

    if (inv) {
        Mod998 inv_n = Mod998(n).inv();
        for (int i = 0; i < n; i++) a[i] *= inv_n;
    }

    return a;
}

vector<Mod998> convolve998(vector<Mod998> a, vector<Mod998> b) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size() - 1) n <<= 1;
    vector<Mod998> fa(n), fb(n);
    for (int i = 0; i < (int)a.size(); i++) fa[i] = a[i];
    for (int i = 0; i < (int)b.size(); i++) fb[i] = b[i];
    fa = NTT998(fa), fb = NTT998(fb);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fa = NTT998(fa, true);
    while ((int)fa.size() > (int)a.size() + (int)b.size() - 1) fa.pop_back();
    return fa;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Mod998> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    for (auto x : convolve998(A, B)) cout << x << ' ';
    cout << endl;
}