/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   05 January 2021 22:49
 * @brief  Follow up:

    Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

 第二个看得不是很明白，先处理第一个吧，思路还是用原数据存储更多信息
 */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void gameOfLife(vector<vector<int>> &board) {
      int m = board.size();
      int n = board[0].size();
      for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              int r = board[i][j] % 10;
              if (1 == r) {
                  if (i - 1 >= 0 && j - 1 >= 0) {
                      board[i - 1][j - 1] += 10;
                  }
                  if (i - 1 >= 0) {
                      board[i - 1][j] += 10;
                  }
                  if (i - 1 >= 0 && j + 1 < n) {
                      board[i - 1][j + 1] += 10;
                  }
                  if (j - 1 >= 0) {
                      board[i][j - 1] += 10;
                  }
                  if (j + 1 < n) {
                      board[i][j + 1] += 10;
                  }
                  if (i + 1 < m && j - 1 >= 0) {
                      board[i + 1][j - 1] += 10;
                  }
                  if (i + 1 < m) {
                      board[i + 1][j] += 10;
                  }
                  if (i + 1 < m && j + 1 < n) {
                      board[i + 1][j + 1] += 10;
                  }
              }
          }
      }

      for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              int q = board[i][j] / 10;
              int r = board[i][j] % 10;
              if (1 == r) {
                  if (q < 2) {
                      board[i][j] = 0;
                  } else if (2 == q || 3 == q) {
                      board[i][j] = 1;
                  } else {
                      board[i][j] = 0;
                  }
              } else {
                  if (3 == q) {
                      board[i][j] = 1;
                  } else {
                      board[i][j] = 0;
                  }
              }
          }
      }
  }
};