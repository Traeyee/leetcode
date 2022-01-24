/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-03 22:40
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        int THE_MAX = 200 * 200 * 100 + 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = THE_MAX;
            }
        }
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int i2 = i + 1;
                if (i2 < m) {
                    dp[i2][j] = min({dp[i2][j], dp[i][j] + grid[i2][j]});
                }
                int j2 = j + 1;
                if (j2 < n) {
                    dp[i][j2] = min({dp[i][j2], dp[i][j] + grid[i][j2]});
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};