/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-03 16:56
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
    int dp(vector<vector<int>>& matrix, int i, int j,
                               map<int, int>& memo) {
        int m = matrix.size(), n = matrix[0].size();
        int key = i * n + j;
        if (memo.count(key)) {
            return memo[key];
        }
        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int max_len = 0;
        for (const auto& dir : dirs) {
            int i2 = i + dir.first, j2 = j + dir.second;
            if (0 <= i2 && i2 < m && 0 <= j2 && j2 < n &&
                matrix[i2][j2] > matrix[i][j]) {
                int len = dp(matrix, i2, j2, memo);
                max_len = len > max_len ? len : max_len;
            }
        }
        memo[key] = 1 + max_len;
        return 1 + max_len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, int> memo;
        
        int max_len = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dp(matrix, i, j, memo);
                max_len = len > max_len ? len : max_len;
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    cout << sol.longestIncreasingPath(matrix) << '\n';

    matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    cout << sol.longestIncreasingPath(matrix) << '\n';

    matrix = {{1}};
    cout << sol.longestIncreasingPath(matrix) << '\n';

    return 0;
}