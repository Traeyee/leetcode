/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-01 15:36
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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[i][w]: 对于前i种硬币，组成w的最小硬币数
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= amount; w++) {
                if (dp[i - 1][w] > 0) {
                    if (dp[i][w] <= 0) {
                        dp[i][w] = dp[i - 1][w];
                    } else {
                        dp[i][w] = dp[i - 1][w] < dp[i][w] ? dp[i - 1][w] : dp[i][w];
                    }
                }
                if (w - coins[i - 1] >= 0 && dp[i][w - coins[i - 1]] >= 0) {
                    if (dp[i][w] <= 0) {
                        dp[i][w] = dp[i][w - coins[i - 1]] + 1;
                    } else {
                        dp[i][w] = dp[i][w - coins[i - 1]] + 1 < dp[i][w] ? dp[i][w - coins[i - 1]] + 1 : dp[i][w];
                    }
                }
            }
        }

        return dp[n][amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins;
    int amount;

    coins = {1,2,5}, amount = 11;
    cout << sol.coinChange(coins, amount) << "\n";

    return 0;
}