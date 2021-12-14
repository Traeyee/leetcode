/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-12 23:05
 * @brief  思路是对了，但代码没写对，下次来写再试
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
   
    int dp(int i, int j, int k, int n,
           unordered_map<int, unordered_map<int, int>>& memo) {
        if (1 == k) {
            return j - i + 1;
        }
        if (i == j) {
            return 1;
        }
        int key = (i - 1) * n + j - 1;
        if (memo.end() != memo.find(key)) {
            if (memo[key].end() != memo[key].find(k)) {
                return memo[key][k];
            }
        } else {
            memo[key] = unordered_map<int, int>();
        }

        int mid = (j - i) / 2 + i;
        int val1 = -1, val2 = -1;
        if (mid - 1 >= i) {
            val1 = dp(i, mid - 1, k - 1, n, memo) + 1;
        }
        if (mid + 1 <= j) {
            val2 = dp(mid + 1, j, k, n, memo) + 1;
        }
        int rst = val1 > val2 ? val1 : val2;
        memo[key][k] = rst;
        return rst;
    }
    int superEggDrop(int k, int n) {
        unordered_map<int, unordered_map<int, int>> memo;
        int rst = dp(1, n, k, n, memo);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k1 = 1; k1 <= k; k1++) {
                    cout << "# " << i << ", " << j << ", " << k1 << ": " << dp(i, j, k1, n, memo) << '\n';
                }
            }
        }
        return rst;
    }
    int superEggDrop__PENDING(int k, int n) {
        // dp[i][j][k]: 实验点在i~j时，只剩下k个蛋的策略步数
        // 比如在第i层实验
        // 若破，则继续需要在i-1下做实验
        // 若不破，则需要i+1上做实验

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 0)));
        unordered_map<int, int> lookback;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j][1] = j - i + 1;
                for (int k1 = 2; k1 <= k; k1++) {
                    int mid = (j - i) / 2 + i;
                    // cout << "# " << i << ", " << mid << ", " << j << ": " <<
                    // k << '\n'; 若破 dp[i][mid - 1][k1 - 1]; 若不破 dp[mid +
                    // 1][j][k1]; 二者取较大 这个公式需要再转化一下 dp[i][j][k1]
                    // = dp[i][mid - 1][k1 - 1] > dp[mid + 1][j][k1]
                    //                    ? dp[i][mid - 1][k1 - 1]
                    //                    : dp[mid + 1][j][k1];
                    if (mid - 1 >= 1) {
                        dp[i][j][k1] = dp[i][mid - 1][k1 - 1] + 1;
                    }
                    if (lookback.end() != lookback.find(i)) {
                        int i0 = lookback[i];
                        dp[i0][j][k1] = dp[i][j][k1] + 1 > dp[i0][j][k1]
                                            ? dp[i][j][k1] + 1
                                            : dp[i0][j][k1];
                    }
                    if (mid + 1 <= n) {
                        lookback[mid + 1] = i;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k1 = 1; k1 <= k; k1++) {
                    cout << "# " << i << ", " << j << ", " << k1 << ": "
                         << dp[i][j][k1] << '\n';
                }
            }
        }

        return dp[1][n][k];
    }

    int superEggDrop__NAIVE(int k, int n) {
        // 先考虑有无限个鸡蛋
        int l = 1, r = n;

        int cnt = 0;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            l = mid + 1;
            cnt++;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    int k, n;

    // k = 1, n = 2;
    // cout << sol.superEggDrop(k, n) << '\n';

    // k = 2, n = 6;
    // cout << sol.superEggDrop(k, n) << '\n';

    // k = 3, n = 14;
    // cout << sol.superEggDrop(k, n) << '\n';

    // k = 1, n = 3;
    // cout << sol.superEggDrop(k, n) << '\n';

    k = 2, n = 9;
    cout << sol.superEggDrop(k, n) << '\n';

    return 0;
}