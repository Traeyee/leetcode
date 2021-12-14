/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-30 14:57
 * @brief  必须养成每一个数组取值都要检查边界的习惯
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
    int numSquares__DP(int n) {
        vector<int> dp(n + 1, 10000);
        for (int i = 1; i <= n; i++) {
            if (i * i <= n) {
                dp[i * i] = 1;
            }
            int k = 1;
            int n2 = i + k * k;
            while (n2 <= n) {
                // cout << "# " << i << "+" << k << "^2\n";
                // cout << n2 << "\n";
                dp[n2] = dp[i] + 1 < dp[n2] ? dp[i] + 1 : dp[n2];
                k++;
                n2 = i + k * k;
            }
        }

        return dp[n];
    }

    int numSquares__NAIVE(int n, unordered_map<int, int>& memo) {
        if (memo.end() != memo.find(n)) {
            return memo[n];
        }

        int i = sqrt(n);
        int res = 10000;
        while (i >= 1) {
            if (i * i == n) {
                res = 1 < res ? 1 : res;
            }
            int rst = numSquares__NAIVE(n - i * i, memo);
            if (rst > 0) {
                res = 1 + rst < res ? 1 + rst : res;
            }
            i--;
        }

        memo[n] = res;
        return res;
    }

    int numSquares(int n) { return numSquares__DP(n); }
};

int main() {
    Solution sol;
    int n;

    n = 12;
    cout << sol.numSquares(n) << "\n";

    n = 13;
    cout << sol.numSquares(n) << "\n";

    return 0;
}