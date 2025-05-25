#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getMinNumber(string n, int s) {
    vector<char> stack;

    for (char c : n) {
        while (!stack.empty() && s > 0 && stack.back() > c) {
            stack.pop_back();
            s--;
        }
        stack.push_back(c);
    }

    while (s > 0) {
        stack.pop_back();
        s--;
    }

    int start = 0;
    while (start < stack.size() && stack[start] == '0') {
        start++;
    }

    if (start == stack.size()) {
        return "0";
    }

    return string(stack.begin() + start, stack.end());
}

int main() {
    string n;
    int s;

    cin >> n >> s;

    cout << getMinNumber(n, s) << endl;

    return 0;
}