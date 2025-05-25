#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个结构体，表示活动的开始时间和结束时间
struct Activity {
    int start;
    int end;
};

// 比较函数，用于按结束时间排序
bool compareByEnd(const Activity &a, const Activity &b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].start >> activities[i].end;
    }

    // 按结束时间排序
    sort(activities.begin(), activities.end(), compareByEnd);

    int count = 0;
    int last_end = 0;

    for (const Activity &act : activities) {
        if (act.start >= last_end) {
            ++count;
            last_end = act.end;
        }
    }

    cout << count << endl;

    return 0;
}