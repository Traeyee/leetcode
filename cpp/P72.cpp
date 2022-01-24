/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-02 20:53
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
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] =
                        min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1;
                }
            }
        }

        return dp[m][n];
    }

    int minDistance0(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int dp[n1 + 1][n2 + 1];

        for (int i = 0; i <= n1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n2; j++) {
            dp[0][j] = j;
        }

        for (int i = 0; i < n1; i++) {
            // cout << "#base" << i << "," << 0 << ":" << dp[i][0] << "\n";
            for (int j = 0; j < n2; j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                    // cout << "#==" << i << "," << j << ":" << dp[i + 1][j + 1]
                    // <<
                    // "\n";
                } else {
                    // dp[i][j] = (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j]
                    //                                         : dp[i][j - 1]) +
                    //            1;
                    // dp[i + 1][j + 1] = dp[i][j] + 1;
                    dp[i + 1][j + 1] =
                        min({dp[i + 1][j], dp[i][j + 1], dp[i][j]}) + 1;
                    // cout << "#!=" << i << "," << j << ":" << dp[i + 1][j + 1]
                    // <<
                    // "\n";
                }
            }
        }

        return dp[n1][n2];
    }
};

int main() {
    Solution s;

    string word1 = "horse", word2 = "ros";
    cout << s.minDistance(word1, word2) << "\n";

    word1 = "intention", word2 = "execution";
    cout << s.minDistance(word1, word2) << "\n";

    return 0;
}