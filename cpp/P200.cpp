/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-28 20:34
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
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> visited;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int key = i * n + j;
                if (visited.end() != visited.find(key)) {
                    continue;
                }
                visited.insert(key);
                if ('1' == grid[i][j]) {
                    // cout << "#  " << i << ", " << j << "\n";
                    cnt++;
                    q.emplace(i, j);
                    while (q.size() > 0) {
                        int i1 = q.front().first, j1 = q.front().second;
                        // cout << "#- " << i1 << ", " << j1 << "\n";
                        for (const auto& dir : dirs) {
                            int i2 = i1 + dir.first;
                            int j2 = j1 + dir.second;
                            if (0 <= i2 && i2 < m && 0 <= j2 && j2 < n) {
                                int key2 = i2 * n + j2;
                                if (visited.end() != visited.find(key2)) {
                                    continue;
                                }
                                visited.insert(key2);
                                if ('1' == grid[i2][j2]) {
                                    q.emplace(i2, j2);
                                }
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        return cnt;
    }

    int numIslands__FALSE(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ('1' == grid[i][j] || '#' == grid[i][j]) {
                    if ('1' == grid[i][j]) {
                        grid[i][j] = '$';
                    }
                    for (const auto& dir : dirs) {
                        int i2 = i + dir.first;
                        int j2 = j + dir.second;
                        if (0 <= i2 && i2 < m && 0 <= j2 && j2 < n &&
                            '1' == grid[i2][j2]) {
                            grid[i2][j2] = '#';
                        }
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ('$' == grid[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid;

    grid = {{'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}};
    cout << sol.numIslands(grid) << "\n";

    grid = {{'1', '0', '1', '1', '1'},
            {'1', '0', '1', '0', '1'},
            {'1', '1', '1', '0', '1'}};
    cout << sol.numIslands(grid) << '\n';

    return 0;
}