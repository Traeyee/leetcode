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
        for (int i = 0; i < m; i++) {
            bool this_row_has0 = false;
            for (int j = 0; j < n; j++) {
                if (0 == matrix[i][j]) {
                    this_row_has0 = true;
                    break;
                }
            }
            for (int j = 0; j < n; j++) {
                // 只关心自己变不变零
                if (this_row_has0) {
                    matrix[i][j] = 0;
                } else if (matrix[i][j]) {
                    // 看看这列有没有零
                    for (int i1 = i + 1; i1 < m; i1++) {
                    }
                }
            }
        }
    }
};