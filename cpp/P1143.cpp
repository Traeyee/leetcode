/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-03 11:06
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
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        int dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n2; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
                }
                // cout << "#" << i << "," << j << ":" << dp[i * (n2 + 1) + j]
                //      << "\n";
            }
        }
                
        return dp[n1][n2];
    }
};

int main() {
    Solution s;

    string text1 = "abcde", text2 = "ace";
    cout << s.longestCommonSubsequence(text1, text2) << "\n";

    return 0;
}