/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-16 16:49
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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool first_row_0 = false, first_col_0 = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (0 == matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if (0 == i) {
                        first_row_0 = true;
                    }
                    if (0 == j) {
                        first_col_0 = true;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (0 == matrix[0][j] || 0 == matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << matrix[i][j] << ", ";
        //     }
        //     cout << '\n';
        // }
        if (first_col_0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (first_row_0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;

    // matrix = {{1,1,1},{1,0,1},{1,1,1}};

    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    sol.setZeroes(matrix);

    return 0;
}