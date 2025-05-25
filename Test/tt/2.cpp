#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {
            cin >> times[i];
        }

        sort(times.begin(), times.end());

        int total_time = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            if (left + 1 == right) {
                total_time += times[right];
                break;
            }

            int option1 = times[left] + times[right];
            int option2 = times[left] + times[left + 1] + times[right] * 2;

            total_time += min(option1, option2);
            right -= 2;
        }

        cout << total_time << endl;
    }

    return 0;
}