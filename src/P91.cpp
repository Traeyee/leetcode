/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-17 10:17
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
    int numDecodings(string s) {
        int n = s.size();
        int dp[n + 1];  // dp[i]: 以s[i]为起始字符的方法数
        // int start = 0;
        // while ('0' == s[start]) {
        //     start++;
        // }
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 0;
            if ('0' == s[i]) {
                continue;
            }
            if (i + 1 <= n) {
                // 1) 取单字符
                dp[i] += dp[i + 1];
            }
            if (i + 2 <= n) {
                // 2) 取双字符
                int q = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (1 <= q && q <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        // for (int i = start; i <= n; i++) {
        //     cout << "# " << i << ": " << dp[i] << "\n";
        // }

        return dp[0];
    }
};

int main() {
    Solution sol;
    string s;

    s = "12";
    cout << sol.numDecodings(s) << "\n";

    s = "226";
    cout << sol.numDecodings(s) << "\n";

    s = "0";
    cout << sol.numDecodings(s) << "\n";

    s = "06";
    cout << sol.numDecodings(s) << "\n";

    return 0;
}