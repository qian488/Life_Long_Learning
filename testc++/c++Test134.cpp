#include <iostream>
#include <vector>
using namespace std;
//pta-KMP专场_【模板】KMP字符串匹配
void get_next(const string &p, vector<int> &ne) {
    int m = p.size();
    ne.resize(m + 1);
    ne[0] = -1;
    int k = -1;
    for (int i = 1; i <= m; i++) {
        while (k != -1 && p[i - 1] != p[k]) {
            k = ne[k];
        }
        ne[i] = ++k;
    }
}

void kmp(const string &t, const string &p) {
    int n = t.size();
    int m = p.size();
    vector<int> ne;
    get_next(p, ne);

    vector<int> positions; // 存储出现的位置

    int i = 0, j = 0;
    while (i < n) {
        while (j != -1 && t[i] != p[j]) {
            j = ne[j];
        }
        i++;
        j++;
        if (j == m) {
            positions.push_back(i - m + 1);
            j = ne[j];
        }
    }

    // 输出出现的位置
    for (int pos : positions) {
        cout << pos << endl;
    }

    // 输出前缀数组next
    cout<<ne[1];
    for (int i=2;i<=m;i++) {
        cout << " ";
        cout<<ne[i];
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    kmp(text, pattern);

    return 0;
}