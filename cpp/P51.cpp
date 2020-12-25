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
  bool check_valid(int row, int col, vector<string> &board, int n) {
      int row1 = row - 1, col1 = col - 1;
      while (row1 >= 0 && col1 >= 0) {
          if ('Q' == board[row1][col1]) {
              return false;
          }
          row1--;
          col1--;
      }

      row1 = row - 1, col1 = col + 1;
      while (row1 >= 0 && col1 < n) {
          if ('Q' == board[row1][col1]) {
              return false;
          }
          row1--;
          col1++;
      }

      return true;
  }

  void _solveNQueens(int row,
                     vector<string> &board,
                     vector<bool> &col_used,
                     int n,
                     vector<vector<string>> &solutions) {
      if (row >= n) {
          auto tmp = board;
          solutions.emplace_back(tmp);
          return;
      }

      int num = 0;

      for (int j = 0; j < n; j++) {
          if (!col_used[j]) {
              if (check_valid(row, j, board, n)) {
                  col_used[j] = true;
                  board[row][j] = 'Q';
                  _solveNQueens(row + 1, board, col_used, n, solutions);
                  board[row][j] = '.';
                  col_used[j] = false;
              }
          }
      }

      return;
  }
  vector<vector<string>> solveNQueens(int n) {
      vector<string> board;
      for (int i = 0; i < n; i++) {
          board.emplace_back(string(n, '.'));
      }
      vector<bool> row_used(n, false);
      vector<bool> col_used(n, false);

      vector<vector<string>> solutions;
      _solveNQueens(0, board, col_used, n, solutions);

      return solutions;
  }
};

int main() {
    Solution s;
    s.solveNQueens(1);
    return 0;
}