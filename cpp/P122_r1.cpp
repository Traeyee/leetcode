/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-17 20:09
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
    int maxProfit(vector<int>& prices) {
        // dp[i][b]: b = 0空手，b = 1持有，最佳状态
        int n = prices.size();
        int dp[n][2];  // 发现i只和i-1有关，甚至可以省下dp的空间
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] > dp[i - 1][1] + prices[i]
                           ? dp[i - 1][0]
                           : dp[i - 1][1] + prices[i];
            dp[i][1] = dp[i - 1][1] > dp[i - 1][0] - prices[i]
                           ? dp[i - 1][1]
                           : dp[i - 1][0] - prices[i];
        }

        return dp[n - 1][0];
    }
};

int main() {
    Solution s;
    vector<int> prices;

    prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << "\n";

    prices = {1, 2, 3, 4, 5};
    cout << s.maxProfit(prices) << "\n";

    prices = {7, 6, 4, 3, 1};
    cout << s.maxProfit(prices) << "\n";

    return 0;
}