/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-03 15:28
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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
    }







    int longestPalindromeSubseq__DP(string s) {
        int n = s.size();
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 1;
            }
        }

        for (int j = 1; j < n; j++) {
            if (s[j - 1] == s[j]) {
                dp[j - 1][j] = 2;
            } else {
                dp[j - 1][j] = 1;
            }
            for (int i = j - 2; i >= 0; i--) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j]
                                                           : dp[i][j - 1];
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution s;

    cout << s.longestPalindromeSubseq("bbbab") << "\n";

    cout << s.longestPalindromeSubseq("cbbd") << "\n";

    return 0;
}