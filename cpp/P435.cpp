/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-05 08:52
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    // 贪心版本，虽然是自己写的，但也是因为已知此题是贪心题目，并没有完全理解
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& x1, vector<int>& x2) {
                 if (x1[0] < x2[0]) {
                     return true;
                 } else if (x1[0] == x2[0]) {
                     return x1[1] < x2[1];
                 }
                 return false;
             });

        int last_start = intervals[0][0], last_end = intervals[0][1];
        int rm_cnt = 0;
        for (int i = 1; i < n; i++) {
            auto& itvl = intervals[i];
            int start = itvl[0], end = itvl[1];
            if (start == last_start) {
                // 必重叠，rm掉
                rm_cnt++;
            } else {
                // 看看有没有重叠
                if (last_end <= start) {
                    // 没重叠
                    last_end = end;
                } else {
                    // 重叠了
                    last_end = end < last_end ? end : last_end;
                    rm_cnt++;
                }
                last_start = start;
            }
        }

        return rm_cnt;
    }

    // 原始DP版本，TL
    int eraseOverlapIntervals0(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [&](vector<int> x1, vector<int> x2) { return x1[1] < x2[1]; });

        vector<int> dp(n, 1);  // 包含区间i的最大区间数目
        for (int j = 1; j < n; j++) {
            int max_cnt = 0;
            for (int i = j - 1; i >= 0; i--) {
                if (intervals[i][1] <= intervals[j][0]) {
                    max_cnt = dp[i] > max_cnt ? dp[i] : max_cnt;
                }
            }
            dp[j] = max_cnt + 1;
        }

        return n - *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;

    intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n";

    intervals = {{1, 2}, {1, 2}, {1, 2}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n";

    intervals = {{1, 2}, {2, 3}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n";

    intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n";

    return 0;
}