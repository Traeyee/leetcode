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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [&](vector<int> x1, vector<int> x2) {
                 return x1[1] < x2[1];
             });

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