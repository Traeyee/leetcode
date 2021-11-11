/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-03 09:49
 * @brief  可以通过先对宽度 w 进行升序排序，如果遇到 w 相同的情况，则按照高度 h 降序排序。之后把所有的 h 作为一个数组，在这个数组上计算 LIS 的长度就是答案
 *         降维成一维DP问题
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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& x1, vector<int>& x2) {
                 if (x1[0] < x2[0]) {
                     return true;
                 } else if (x1[0] == x2[0]) {
                     if (x1[1] < x2[1]) {
                         return true;
                     }
                 }
                 return false;
             });
        int n = envelopes.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (envelopes[i][0] < envelopes[j][0] &&
                    envelopes[i][1] < envelopes[j][1]) {
                    int tmp_num = dp[i] + 1;
                    // cout << "#" << i << "," << j << ":" << tmp_num << "?"
                    //      << dp[j] << "\n";
                    dp[j] = tmp_num > dp[j] ? tmp_num : dp[j];
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << s.maxEnvelopes(envelopes) << "\n";

    envelopes = {{1, 1}, {1, 1}, {1, 1}};
    cout << s.maxEnvelopes(envelopes) << "\n";

    return 0;
}