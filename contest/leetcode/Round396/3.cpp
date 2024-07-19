class Solution {
public:
    int minAnagramLength(string s) {
        int ans=0,n=s.size();
        for (int i = n; i > 1; i--) {
            if (n % i == 0) {
                int t = n / i;
                unordered_map<char, int> tt;
                for (int k = 0; k < t; ++k) tt[s[k]]++;
                bool sign = true;
                for (int j = 0; j < n; j += t) {
                    unordered_map<char, int> kk;
                    for (int k = j; k < j + t; k++) kk[s[k]]++;
                    if (kk != tt) {
                        sign = false;
                        break;
                    }
                }
                if (sign) {
                    return t;
                }
            }
    }
    return n;
    }
};

/*
class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        // 计算整个字符串里每种字母的出现次数
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        // 检查子串的长度是否可能为 len
        auto check = [&](int len) {
            for (int i = 0; i < n; i += len) {
                // 统计当前子串每种字母的出现次数
                int tmp[26] = {0};
                for (int j = 0; j < len; j++) tmp[s[i + j] - 'a']++;
                for (int j = 0; j < 26; j++) if (tmp[j] * (n / len) != cnt[j]) return false;
            }
            return true;
        };

        // 枚举子串的长度
        for (int i = 1; i <= n; i++) if (n % i == 0 && check(i)) return i;
        return -1;
    }
};
*/