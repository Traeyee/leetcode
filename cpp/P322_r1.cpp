/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-04 21:38
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int MY_MAX = 100000;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, MY_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // dp[i][w] = 用i / 不用i里，较小的
        for (int i = 0; i < n; i++) {
            for (int w = 0; w <= amount; w++) {
                // 不用i
                dp[i + 1][w] = min({dp[i + 1][w] + 1, dp[i][w]});
                // 用i
                int w1 = w - coins[i];
                if (w1 >= 0) {
                    dp[i + 1][w] = min({dp[i + 1][w1] + 1, dp[i + 1][w]});
                }
            }
        }
        if (dp[n][amount] == MY_MAX) {
            return -1;
        }
        return dp[n][amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins;
    int amount;

    coins = {1, 2, 5}, amount = 11;
    cout << sol.coinChange(coins, amount) << "\n";

    return 0;
}