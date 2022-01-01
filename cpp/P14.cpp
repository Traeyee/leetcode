/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-16 23:05
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
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = 0x3f3f;
        for (const auto& s : strs) {
            min_len = s.size() < min_len ? s.size() : min_len;
        }

        for (int i = 0; i < min_len; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0].substr(0, min_len);
    }
};