/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   24 November 2020 10:19
 * @brief  
 */
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 暴力法
class Solution {
  typedef unordered_map<int, vector<pair<int, int>>> int2vec;
 public:
  bool check_valid(int row, int col, vector<vector<bool> > &point_used, int n) {
      int row1 = row - 1, col1 = col - 1;
      while (row1 >= 0 && col1 >= 0) {
          if (point_used[row1][col1]) {
              return false;
          }
          row1--;
          col1--;
      }

      row1 = row - 1, col1 = col + 1;
      while (row1 >= 0 && col1 < n) {
          if (point_used[row1][col1]) {
              return false;
          }
          row1--;
          col1++;
      }

      return true;
  }

  int _totalNQueens(int row, vector<vector<bool> > &point_used, vector<bool> &col_used, int n) {
      if (row >= n) {
          return 1;
      }

      int num = 0;

      for (int j = 0; j < n; j++) {
          if (!col_used[j]) {
              if (check_valid(row, j, point_used, n)) {
                  col_used[j] = true;
                  point_used[row][j] = true;
                  num += _totalNQueens(row + 1, point_used, col_used, n);
                  point_used[row][j] = false;
                  col_used[j] = false;
              }
          }
      }

      return num;
  }
  int totalNQueens(int n) {
      vector<vector<bool> > point_used;
      for (int i = 0; i < n; i++) {
          vector<bool> tmp(n, false);
          point_used.emplace_back(tmp);
      }
      vector<bool> row_used(n, false);
      vector<bool> col_used(n, false);
      return _totalNQueens(0, point_used, col_used, n);
  }
};

int main() {
    Solution s;
    cout << s.totalNQueens(1);
    return 0;
}