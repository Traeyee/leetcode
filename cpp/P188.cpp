/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   02 January 2021 12:10
 * @brief  O(n)-time 8ms Accepted Solution with Detailed Explanation (C++)
 * 构造互不冲突的profit
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define max(x1, x2) (x1 > x2 ? x1 : x2)

class Solution {
 public:
  int maxProfit(int k, vector<int> &prices) {
      int n = prices.size();
      if (n <= 1) {
          return 0;
      }
      int interval_max[n][n];
      interval_max[n - 1][n - 1] = prices[n - 1];
      for (int j = n - 1; j >= 0; j--) {
          interval_max[j][j] = prices[j];
          for (int i = j - 1; i >= 0; i--) {
              interval_max[i][j] = max(prices[i], interval_max[i + 1][j]);
          }
      }

      int ddl_profit[k + 1][n];  // 到第i天到了最多l次交易的最大利润
      for (int i = 0; i < n; i++) {
          ddl_profit[0][i] = 0;
      }
      for (int l = 1; l <= k; l++) {
          for (int i = 0; i < n; i++) {
              ddl_profit[l][i] = 0;
              for (int j = 0; j < i; j++) {
                  auto profit = ddl_profit[l - 1][j];
                  if (prices[j] < interval_max[j + 1][i]) {
                      profit += interval_max[j + 1][i] - prices[j];
                  }
                  ddl_profit[l][i] = max(ddl_profit[l][i], profit);
              }
              // cout << l << "," << i << ":" << ddl_profit[l][i] << "\n";
          }
      }
      return ddl_profit[k][n - 1];
  }
};

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    Solution s;
    cout << s.maxProfit(2, prices) << "\n";
    return 0;
};