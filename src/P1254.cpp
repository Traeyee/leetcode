/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-01 21:48
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
    // dfs到一个边界的，就算false，其它算true
    bool is_island(vector<vector<int>>& grid, int i, int j,
                   unordered_map<int, bool>& memo) {
        int m = grid.size(), n = grid[0].size();
        int key = i * n + j;

        if (0 == i || m - 1 == i || 0 == j || n - 1 == j) {
            return false;
        }

        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        bool res = true;
        for (const auto& dir : dirs) {
            int i2 = i + dir.first, j2 = j + dir.second;
            // cout << "# " << i2 << ", " << j2 << '\n';
            if (0 == grid[i2][j2]) {
                int key2 = i2 * n + j2;
                if (memo.end() == memo.find(key2)) {
                    memo[key2] = true;
                    memo[key2] = is_island(grid, i2, j2, memo);
                }
                if (!memo[key2]) {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        unordered_map<int, bool> memo;
        int cnt = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                int key = i * n + j;
                if (0 == grid[i][j] && memo.end() == memo.find(key)) {
                    memo[key] = true;
                    if (is_island(grid, i, j, memo)) {
                        cout << "# " << i << ", " << j << "\n";
                        cnt++;
                    } else {
                        memo[key] = false;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // grid = {{1, 1, 1, 1, 1, 1, 1, 0},
    //         {1, 0, 0, 0, 0, 1, 1, 0},
    //         {1, 0, 1, 0, 1, 1, 1, 0},
    //         {1, 0, 0, 0, 0, 1, 0, 1},
    //         {1, 1, 1, 1, 1, 1, 1, 0}};
    // cout << sol.closedIsland(grid) << '\n';

    // grid = {{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}};
    // cout << sol.closedIsland(grid) << '\n';

    // grid = {{1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0,
    // 1},
    //         {1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0,
    //         1}, {1, 1, 1, 1, 1, 1, 1}};
    // cout << sol.closedIsland(grid) << '\n';

    grid = {{0, 0, 1, 1, 0, 1, 0, 0, 1, 0}, {1, 1, 0, 1, 1, 0, 1, 1, 1, 0},
            {1, 0, 1, 1, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
            {1, 0, 1, 0, 1, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
            {1, 1, 1, 0, 0, 1, 0, 1, 0, 1}, {1, 1, 1, 0, 1, 1, 0, 1, 1, 0}};
    cout << sol.closedIsland(grid) << '\n';

    return 0;
}