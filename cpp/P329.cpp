/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-03 16:56
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
    void longestIncreasingPath(vector<vector<int>>& matrix, int i, int j,
                               vector<int>& cur_path,
                               vector<vector<bool>>& used, int& max_len) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        bool is_end = true;
        for (const auto& dir : dirs) {
            int i2 = i + dir.first, j2 = j + dir.second;
            if (0 <= i2 && i2 < m && 0 <= j2 && j2 < n && !used[i2][j2] &&
                matrix[i2][j2] > matrix[i][j]) {
                used[i2][j2] = true;
                cur_path.emplace_back(matrix[i2][j2]);
                longestIncreasingPath(matrix, i2, j2, cur_path, used, max_len);
                cur_path.pop_back();
                used[i2][j2] = false;
                is_end = false;
            }
        }
        if (is_end && cur_path.size() > max_len) {
            max_len = cur_path.size();
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> cur_path;
        vector<vector<bool>> used(m, vector<bool>(n, false));
        int max_len = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                used[i][j] = true;
                cur_path.emplace_back(matrix[i][j]);
                longestIncreasingPath(matrix, i, j, cur_path, used, max_len);
                cur_path.pop_back();
                used[i][j] = false;
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