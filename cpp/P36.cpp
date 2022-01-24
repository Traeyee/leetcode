/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-17 09:34
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> visited(9);
        for (int i = 0; i < 9; i++) {
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j < 9; j++) {
                if ('.' == board[i][j]) {
                    continue;
                }
                int idx = board[i][j] - '1';
                if (visited[idx]) {
                    return false;
                }
                visited[idx] = true;
            }
        }
        for (int j = 0; j < 9; j++) {
            fill(visited.begin(), visited.end(), false);
            for (int i = 0; i < 9; i++) {
                if ('.' == board[i][j]) {
                    continue;
                }
                int idx = board[i][j] - '1';
                if (visited[idx]) {
                    return false;
                }
                visited[idx] = true;
            }
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                fill(visited.begin(), visited.end(), false);
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if ('.' == board[i][j]) {
                            continue;
                        }
                        int idx = board[i][j] - '1';
                        if (visited[idx]) {
                            return false;
                        }
                        visited[idx] = true;
                    }
                }
            }
        }
        return true;
    }
};