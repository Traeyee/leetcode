/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-02 19:25
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 100000));
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        vector<int> dirs = {-1, 0, 1};
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                for (int dir : dirs) {
                    int j2 = j + dir;
                    if (0 <= j2 && j2 < n) {
                        int sum1 = dp[i][j] + matrix[i + 1][j2];
                        dp[i + 1][j2] = sum1 < dp[i + 1][j2] ? sum1 : dp[i + 1][j2];
                    }
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
    int minFallingPathSum0(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        bool valid[n][n];

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
            valid[0][j] = true;
            for (int i = 1; i < n; i++) {
                valid[i][j] = false;
            }
        }

        int dirs[3] = {-1, 0, 1};
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                for (const auto& dir : dirs) {
                    int j2 = j + dir;
                    if (0 <= j2 && j2 < n) {
                        int tmp_sum = dp[i][j] + matrix[i + 1][j2];
                        if (valid[i + 1][j2]) {
                            dp[i + 1][j2] = tmp_sum < dp[i + 1][j2]
                                                ? tmp_sum
                                                : dp[i + 1][j2];
                        } else {
                            dp[i + 1][j2] = tmp_sum;
                            valid[i + 1][j2] = true;
                        }
                    }
                }
            }
        }

        int min_sum = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            min_sum = dp[n - 1][j] < min_sum ? dp[n - 1][j] : min_sum;
        }
        return min_sum;
    }
};
