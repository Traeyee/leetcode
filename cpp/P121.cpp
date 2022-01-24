/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   27 December 2020 15:58
 * @brief  
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
      if (prices.size() <= 1) {
          return 0;
      }

      vector<int> dp(prices.size());
      dp[0] = prices[0];

      for (int i = 1; i < prices.size(); i++) {
          if (prices[i] < dp[i - 1]) {
              dp[i] = prices[i];
          } else {
              dp[i] = dp[i - 1];
          }
      }

      int max_profit = 0;
      for (int i = 1; i < prices.size(); i++) {
          auto profit = prices[i] - dp[i - 1];
          if (profit > max_profit) {
              max_profit = profit;
          }
      }

      return max_profit;
  }
};

int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices);
    return 0;
}