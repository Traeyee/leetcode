/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-16 14:23
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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i + 1 < m) {
                    dp[i][j] += dp[i + 1][j];
                }
                if (j + 1 < n) {
                    dp[i][j] += dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};