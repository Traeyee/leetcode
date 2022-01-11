/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-03 14:16
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, ~(1 << 31)));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i + 1 < m) {
                    dp[i][j] = dp[i + 1][j] + grid[i][j] < dp[i][j]
                                   ? dp[i + 1][j] + grid[i][j]
                                   : dp[i][j];
                }
                if (j + 1 < n) {
                    dp[i][j] = dp[i][j + 1] + grid[i][j] < dp[i][j]
                                   ? dp[i][j + 1] + grid[i][j]
                                   : dp[i][j];
                }
            }
        }
        return dp[0][0];
    }
};