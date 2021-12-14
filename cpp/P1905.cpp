/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-02 10:06
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
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
             int j, unordered_set<int>& visited) {
        int m = grid1.size(), n = grid1[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return true;
        }

        if (0 == grid1[i][j] && 1 == grid2[i][j]) {
            return false;
        }
        if (0 == (grid1[i][j] & grid2[i][j])) {
            return true;
        }

        int key = i * n + j;
        if (visited.end() != visited.find(key)) {
            return true;
        }
        visited.insert(key);

        bool res = true;
        res &= dfs(grid1, grid2, i - 1, j, visited);
        res &= dfs(grid1, grid2, i + 1, j, visited);
        res &= dfs(grid1, grid2, i, j - 1, visited);
        res &= dfs(grid1, grid2, i, j + 1, visited);

        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        unordered_set<int> visited;
        int m = grid1.size(), n = grid1[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int key = i * n + j;
                if (1 == (grid1[i][j] & grid2[i][j]) &&
                    visited.end() == visited.find(key)) {
                    if (dfs(grid1, grid2, i, j, visited)) {
                        cnt++;
                        // cout << "# " << i << ", " << j << '\n';
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid1, grid2;

    grid1 = {{1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1},
             {0, 0, 0, 0, 0},
             {1, 0, 0, 0, 0},
             {1, 1, 0, 1, 1}},
    grid2 = {{1, 1, 1, 0, 0},
             {0, 0, 1, 1, 1},
             {0, 1, 0, 0, 0},
             {1, 0, 1, 1, 0},
             {0, 1, 0, 1, 0}};
    cout << sol.countSubIslands(grid1, grid2) << '\n';

    grid1 = {{1, 0, 1, 0, 1},
             {1, 1, 1, 1, 1},
             {0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1},
             {1, 0, 1, 0, 1}},
    grid2 = {{0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1},
             {0, 1, 0, 1, 0},
             {0, 1, 0, 1, 0},
             {1, 0, 0, 0, 1}};
    cout << sol.countSubIslands(grid1, grid2) << '\n';

    return 0;
}