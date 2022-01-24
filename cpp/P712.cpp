/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-03 11:35
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
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int dp[n1 + 1][n2 + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min({dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1],
                             dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1]});
                }
            }
        }

        return dp[n1][n2];
    }
};

int main() {
    Solution s;

    string s1 = "sea", s2 = "eat";
    cout << s.minimumDeleteSum(s1, s2) << "\n";

    s1 = "delete", s2 = "leet";
    cout << s.minimumDeleteSum(s1, s2) << "\n";

    return 0;
}