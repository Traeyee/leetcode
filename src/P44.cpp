/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-15 08:59
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
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // dp[i][j]: s[i...n-1]与p[j...m-1]匹配结果
        dp[n][m] = true;
        for (int j = m - 1; j >= 0; j--) {
            if ('*' != p[j]) {
                break;
            }
            dp[n][j] = true;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == p[j] || '?' == p[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if ('*' == p[j]) {
                    // 常数时间，不嫌多
                    bool cond0 = dp[i][j + 1];      // 匹配0次
                    // bool cond1 = dp[i + 1][j + 1];  // 匹配exactly1次
                    bool cond2 = dp[i + 1][j];      // 匹配1次以上
                    dp[i][j] = cond0 || cond2;
                }
            }
        }

        return dp[0][0];
    }

    bool isMatch(string s, int i, string p, int j,
                 unordered_map<string, bool>& memo) {
        // cout << "# " << i << ", " << j << "\n";
        stringstream ss;
        ss << i << '-' << j;
        string key = ss.str();
        if (memo.end() != memo.find(key)) {
            return memo[key];
        }

        if (s.size() == i) {
            if (p.size() == j) {
                return true;
            } else {
                if ('*' == p[j]) {
                    bool rst = isMatch(s, i, p, j + 1, memo);
                    memo[key] = rst;
                    return rst;
                }
                return false;
            }
        } else if (p.size() == j) {
            return false;
        }

        if (s[i] == p[j]) {
            bool rst = isMatch(s, i + 1, p, j + 1, memo);
            memo[key] = rst;
            return rst;
        } else {
            if ('?' == p[j]) {
                bool rst = isMatch(s, i + 1, p, j + 1, memo);
                memo[key] = rst;
                return rst;
            } else if ('*' == p[j]) {
                bool cond0 = isMatch(s, i, p, j + 1, memo);  // 使用星号零次
                bool cond1 = isMatch(s, i + 1, p, j, memo);  // 使用星号一次
                bool rst = cond0 || cond1;
                memo[key] = rst;
                return rst;
            }
            memo[key] = false;
            return false;
        }
    }

    // baseline，正确但TL，试用下动态规划
    bool isMatch0(string s, string p) {
        unordered_map<string, bool> memo;
        return isMatch(s, 0, p, 0, memo);
    }
};

int main() {
    Solution sol;
    string s, p;

    s = "aa", p = "a";
    cout << sol.isMatch(s, p) << "\n";

    s = "aa", p = "*";
    cout << sol.isMatch(s, p) << "\n";

    s = "cb", p = "?a";
    cout << sol.isMatch(s, p) << "\n";

    s = "adceb", p = "*a*b";
    cout << sol.isMatch(s, p) << "\n";

    s = "acdcb", p = "a*c?b";
    cout << sol.isMatch(s, p) << "\n";

    s = "abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab",
    p = "*aabb***aa**a******aa*";
    cout << sol.isMatch(s, p) << "\n";

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
    p = "*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*";
    cout << sol.isMatch(s, p) << "\n";

    s = "", p = "******";
    cout << sol.isMatch(s, p) << "\n";

    return 0;
}