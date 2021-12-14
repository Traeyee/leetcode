/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-15 10:29
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int upper_bound = 0, right_bound = n - 1, lower_bound = m - 1,
            left_bound = 0;
        vector<int> res;
        int dir = 0, i = 0, j = 0;

        while (upper_bound <= i && i <= lower_bound && left_bound <= j &&
               j <= right_bound) {
            res.push_back(matrix[i][j]);
            if (0 == dir) {
                if (j == right_bound) {
                    upper_bound = i + 1;
                    dir = 1;
                    i++;
                } else {
                    j++;
                }
            } else if (1 == dir) {
                if (i == lower_bound) {
                    right_bound = j - 1;
                    dir = 2;
                    j--;
                } else {
                    i++;
                }
            } else if (2 == dir) {
                if (j == left_bound) {
                    lower_bound = i - 1;
                    dir = 3;
                    i--;
                } else {
                    j--;
                }
            } else if (3 == dir) {
                if (i == upper_bound) {
                    left_bound = j + 1;
                    dir = 0;
                    j++;
                } else {
                    i--;
                }
            }
        }
        return res;
    }
};

