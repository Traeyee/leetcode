/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   25 December 2020 09:52
 * @brief  
 */

class Solution {
 public:
  void _rotate(int row, int col, int n, vector<vector<int>>& matrix) {
      if (n < 1) {
          return;
      }

      for (int k = 0; k < n - 1; k++) {
          // 上->右
          int tmp = matrix[row + k][col + n - 1];
          matrix[row + k][col + n - 1] = matrix[row][col + k];
          // 右->下
          int tmp2 = matrix[row + n - 1][col + n - 1 - k];
          matrix[row + n - 1][col + n - 1 - k] = tmp;
          // 左->上
          matrix[row][col + k] = matrix[row + n - 1 - k][col];
          // 下->左
          matrix[row + n - 1 - k][col] = tmp2;
      }
      _rotate(row + 1, col + 1, n - 2, matrix);
  }
  void rotate(vector<vector<int>>& matrix) {
      _rotate(0, 0, matrix.size(), matrix);
  }
};

int main() {

    return 0;
}