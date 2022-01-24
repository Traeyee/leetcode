/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-16 20:32
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
    bool exist(vector<vector<char>>& board, string word, int pos, int i, int j,
               vector<vector<bool>>& used) {
        int n = word.size();
        if (pos == n) {
            return true;
        }
        if (board[i][j] != word[pos]) {
            return false;
        }
        if (pos == n - 1) {
            return true;
        }

        vector<pair<int, int>> positions = {
            {i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}};
        for (const auto& p : positions) {
            int i2 = p.first, j2 = p.second;
            if (0 <= i2 && i2 < board.size() && 0 <= j2 &&
                j2 < board[0].size()) {
                if (!used[i2][j2]) {
                    used[i2][j2] = true;
                    if (exist(board, word, pos + 1, i2, j2, used)) {
                        return true;
                    }
                    used[i2][j2] = false;
                }
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(),
                                  vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                used[i][j] = true;
                if (exist(board, word, 0, i, j, used)) {
                    return true;
                }
                used[i][j] = false;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board;
    string word;

    board = {{'a'}};
    word = "a";
    cout << sol.exist(board, word) << "\n";

    return 0;
}