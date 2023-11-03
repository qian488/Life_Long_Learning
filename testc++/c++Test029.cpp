#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> numToIndex;
    for (int i = 0; i < n; i++) {
        if (numToIndex.find(nums[i]) == numToIndex.end()) {
            numToIndex[nums[i]] = i + 1;
        }
    }

    vector<int> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    for (int i = 0; i < m; i++) {
        if (numToIndex.find(queries[i]) != numToIndex.end()) {
            cout << numToIndex[queries[i]] << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << "\n";

    return 0;
}