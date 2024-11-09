#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s == "ABC") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}