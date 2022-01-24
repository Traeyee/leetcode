/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-04 16:50
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
    int count_no_greater_than(vector<vector<int>>& matrix, int row, int col) {
        int n = matrix.size();
        int cnt = 0;
        int i = row, j = col;
        while (i < n && j >= 0) {
            if (matrix[i][j] <= matrix[row][col]) {
                cnt += i + 1;
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int i = 0, j = n - 1;
        while (i < n && j >= 0) {
            int cnt = count_no_greater_than(matrix, i, j);
            if (cnt < k) {  // 太小，要增大
                i = (i + 1 + n - 1) / 2;
            } else if (cnt > k) {
                j = (0 + j - 1) / 2;
            } else {
                return matrix[i][j];
            }
        }

        return 0;
    }
};
