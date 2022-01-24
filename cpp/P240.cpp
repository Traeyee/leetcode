/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-30 12:06
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && 0 <= col) {
            if (matrix[row][col] < target) {
                row++;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int top, int bottom,
                      int left, int right, int target) {
        cout << "# " << top << ", " << bottom << ", " << left << ", " << right
             << "\n";
        int m = matrix.size(), n = matrix[0].size();
        if (top > bottom || left > right) {
            return false;
        }

        int mid1 = (top + bottom) / 2, mid2 = (left + right) / 2;
        cout << "## " << mid1 << ", " << mid2 << "\n";
        if (matrix[mid1][mid2] == target) {
            return true;
        } else if (matrix[mid1][mid2] < target) {
            if (searchMatrix(matrix, top, mid1, mid2 + 1, right, target)) {
                return true;
            }
            if (searchMatrix(matrix, mid1 + 1, bottom, left, mid2, target)) {
                return true;
            }
            if (searchMatrix(matrix, mid1 + 1, bottom, mid2 + 1, right,
                             target)) {
                return true;
            }
        } else if (matrix[mid1][mid2] > target) {
            if (searchMatrix(matrix, top, mid1 - 1, mid2, right, target)) {
                return true;
            }
            if (searchMatrix(matrix, mid1, bottom, left, mid2 - 1, target)) {
                return true;
            }
            if (searchMatrix(matrix, top, mid1 - 1, left, mid2 - 1, target)) {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix0(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        return searchMatrix(matrix, 0, m - 1, 0, n - 1, target);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    int target;

    matrix = {{5}, {6}};
    target = 6;
    cout << sol.searchMatrix(matrix, target) << "\n";

    matrix = {{1, 2, 3, 4, 5},
              {6, 7, 8, 9, 10},
              {11, 12, 13, 14, 15},
              {16, 17, 18, 19, 20},
              {21, 22, 23, 24, 25}};
    target = 5;
    cout << sol.searchMatrix(matrix, target) << "\n";

    return 0;
}