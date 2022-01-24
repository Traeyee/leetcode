/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-08 22:33
 * @brief  把回溯法写完整点没有坏处
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
    bool solveSudoku(vector<vector<char>>& board, int idx,
                     vector<unordered_map<char, int>>& row_counter,
                     vector<unordered_map<char, int>>& col_counter,
                     vector<unordered_map<char, int>>& box_counter) {
        int i, j, idx1 = idx;
        while (idx1 < 81) {
            i = idx1 / 9, j = idx1 % 9;
            if ('.' == board[i][j]) {
                break;
            }
            idx1++;
        }
        if (81 == idx1) {
            return true;
        }

        for (int l = 1; l <= 9; l++) {
            char c = '0' + l;
            int i_box = (i / 3) * 3 + j / 3;
            if (!row_counter[i][c] && !col_counter[j][c] &&
                !box_counter[i_box][c]) {
                row_counter[i][c]++;
                col_counter[j][c]++;
                box_counter[i_box][c]++;
                board[i][j] = c;
                if (solveSudoku(board, idx1 + 1, row_counter, col_counter,
                                box_counter)) {
                    return true;
                }
                board[i][j] = '.';
                box_counter[i_box][c]--;
                col_counter[j][c]--;
                row_counter[i][c]--;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> row_counter(
            9, unordered_map<char, int>());
        vector<unordered_map<char, int>> col_counter(
            9, unordered_map<char, int>());
        vector<unordered_map<char, int>> box_counter(
            9, unordered_map<char, int>());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if ('.' != c) {
                    row_counter[i][c]++;
                    col_counter[j][c]++;
                    box_counter[(i / 3) * 3 + j / 3][c]++;
                }
            }
        }
        solveSudoku(board, 0, row_counter, col_counter, box_counter);
    }
};