/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-01 17:40
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
    string get_coord_key(int i, int j) {
        stringstream ss;
        ss << i << "-" << j;
        return ss.str();
    }

    vector<string> split(string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        unordered_set<string> holy;
        queue<pair<int, int>> q;
        for (size_t j = 0; j < n - 1; j++) {
            if ('O' == board[0][j]) {
                q.push(make_pair(0, j));
            }
        }
        for (size_t i = 0; i < m - 1; i++) {
            if ('O' == board[i][n - 1]) {
                q.push(make_pair(i, n - 1));
            }
        }
        for (size_t j = 1; j < n; j++) {
            if ('O' == board[m - 1][j]) {
                q.push(make_pair(m - 1, j));
            }
        }
        for (size_t i = 1; i < m; i++) {
            if ('O' == board[i][0]) {
                q.push(make_pair(i, 0));
            }
        }

        stringstream ss;
        while (q.size() > 0) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            string key = get_coord_key(i, j);
            holy.insert(key);

            vector<pair<int, int>> neighbours = {
                {i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}};
            for (auto p : neighbours) {
                int i1 = p.first, j1 = p.second;
                if (0 <= i1 && i1 < m && 0 <= j1 && j1 < n) {
                    if ('O' == board[i1][j1]) {
                        key = get_coord_key(i1, j1);
                        if (holy.end() == holy.find(key)) {
                            holy.insert(key);
                            q.push(make_pair(i1, j1));
                        }
                    }
                }
            }
        }

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                auto key = get_coord_key(i, j);
                if (holy.end() == holy.find(key)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};