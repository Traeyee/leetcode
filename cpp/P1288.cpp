/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-15 18:45
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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int>& x1, vector<int>& x2) {
            if (x1[0] < x2[0]) {
                return true;
            } else if (x1[0] == x2[0]) {
                return x1[1] > x2[1];
            }
            return false;
        };
        sort(intervals.begin(), intervals.end(), cmp);

        int rightmost_end = -1;
        int rm_cnt = 0;
        for (const auto& itvl : intervals) {
            if (itvl[1] <= rightmost_end) {
                rm_cnt++;
            } else {
                rightmost_end = itvl[1];
            }
        }

        return intervals.size() - rm_cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;

    intervals = {{1, 4}, {3, 6}, {2, 8}};
    cout << sol.removeCoveredIntervals(intervals) << "\n";

    intervals = {{1, 4}, {2, 3}};
    cout << sol.removeCoveredIntervals(intervals) << "\n";

    intervals = {{0, 10}, {5, 12}};
    cout << sol.removeCoveredIntervals(intervals) << "\n";

    intervals = {{3, 10}, {4, 10}, {5, 11}};
    cout << sol.removeCoveredIntervals(intervals) << "\n";

    intervals = {{1, 2}, {1, 4}, {3, 4}};
    cout << sol.removeCoveredIntervals(intervals) << "\n";

    return 0;
}