/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-02 09:37
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
    int dfs(vector<vector<int>>& grid, int i, int j,
            unordered_set<int>& visited) {
        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int res = 1;
        for (const auto& dir : dirs) {
            int i2 = i + dir.first, j2 = j + dir.second;
            if (i2 < 0 || i2 >= m || j2 < 0 || j2 >= n) {
                continue;
            }
            int key2 = i2 * n + j2;
            if (1 == grid[i2][j2] && visited.end() == visited.find(key2)) {
                visited.insert(key2);
                res += dfs(grid, i2, j2, visited);
            }
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> visited;
        int max_area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int key = i * n + j;
                if (1 == grid[i][j] && visited.end() == visited.find(key)) {
                    visited.insert(key);
                    int rst = dfs(grid, i, j, visited);
                    max_area = rst > max_area ? rst : max_area;
                }
            }
        }
        return max_area;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << sol.maxAreaOfIsland(grid) << '\n';

    grid = {{0, 0, 0, 0, 0, 0, 0, 0}};
    cout << sol.maxAreaOfIsland(grid) << '\n';

    grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
    cout << sol.maxAreaOfIsland(grid) << '\n';

    grid = {{1}};
    cout << sol.maxAreaOfIsland(grid) << '\n';

    return 0;
}