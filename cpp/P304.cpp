/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-07 19:52
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

class NumMatrix {
   public:
    vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix_sum = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int row_sum = 0;
            for (int j = 0; j < n; j++) {
                row_sum += matrix[i][j];
                int sum = row_sum;
                if (i - 1 >= 0) {
                    sum += prefix_sum[i - 1][j];
                }
                prefix_sum[i][j] = sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = prefix_sum[row2][col2];
        if (row1 - 1 >= 0) {
            res -= prefix_sum[row1 - 1][col2];
        }
        if (col1 - 1 >= 0) {
            res -= prefix_sum[row2][col1 - 1];
        }
        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            res += prefix_sum[row1 - 1][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */