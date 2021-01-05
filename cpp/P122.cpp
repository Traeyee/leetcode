/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   27 December 2020 15:58
 * @brief  我现在发现，极大值点是卖出点
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // 极值版本
  int maxProfit(vector<int> &prices) {
      int n = prices.size();
      if (n <= 1) {
          return 0;
      }
      // 极大值与极大值不可能相邻，极小值与极小值也不可能相邻
      // -1: 买入点；0：不是；1：卖出点
      vector<int> point_types(n);
      if (prices[0] < prices[1]) {
          point_types[0] = -1;
      } else {
          point_types[0] = 0;
      }
      if (prices[n - 1] > prices[n - 2]) {
          point_types[n - 1] = 1;
      } else {
          point_types[n - 1] = 0;
      }
      for (int i = 1; i < n - 1; i++) {
          if (prices[i - 1] == prices[i] && prices[i] == prices[i + 1]) {
              point_types[i] = 0;
          } else if (prices[i - 1] >= prices[i] && prices[i] <= prices[i + 1]) {
              point_types[i] = -1;
          } else if (prices[i - 1] <= prices[i] && prices[i] >= prices[i + 1]) {
              point_types[i] = 1;
          } else {
              point_types[i] = 0;
          }
      }

      int m = n - 1;  // 最后一个极大值点
      while (m >= 0) {
          if (1 == point_types[m]) {
              break;
          }
          m--;
      }

      int state = -1;
      int profit = 0;
      for (int i = 0; i <= m; i++) {
          if (point_types[i] == state) {
              profit += state * prices[i];
              state *= -1;
          }
      }

      return profit;
  }

      // DP版本
  int maxProfit1(vector<int> &prices) {
      vector<int> dp(prices.size(), 0);  // 第i天sell的max profit
      // 第0天买，第i天卖
      for (int i = 1; i < prices.size(); i++) {
          if (prices[i] > prices[0]) {
              dp[i] = prices[i] - prices[0];
          }
      }
      unordered_map<string, int> min_record;

      // 第i天卖，i+1 ~ k-1里挑一天买，第k天卖
      for (int i = 0; i < prices.size(); i++) {  // 边界可能有bug
          for (int k = i + 2; k < prices.size(); k++) {  // 需要更新的那天
              // [i + 1, k - 1]中的最小值
              stringstream ss;
              ss << i + 1;
              ss << "\t";
              ss << k - 1;
              auto key = ss.str();
              if (min_record.end() == min_record.find(key)) {
                  min_record[key] = 0x3f3f;
                  for (int j = i + 1; j < k; j++) {
                      if (prices[j] < min_record[key]) {
                          min_record[key] = prices[j];
                      }
                  }
              }
              if (min_record[key] < prices[k]) {
                  auto profit = prices[k] - min_record[key] + dp[i];
                  dp[k] = profit > dp[k] ? profit : dp[k];
                  // cout << i << ":" << dp[i] << ", " << key << ":" << min_record[key] << ", " << k << ": " << dp[k] << "\n";
              }
          }
      }

      int max_profit = 0;
      for (int i = 0; i < prices.size(); i++) {
          if (dp[i] > max_profit) {
              max_profit = dp[i];
          }
      }
      return max_profit;
  }
  // 原始版本递归，有点见慢的
  int _maxProfit(vector<int> &prices, int sell_day, unordered_map<int, int> &record) {
      int max_profit = 0;
      for (int i = sell_day - 1; i >= 0; i--) {
          if (prices[i] < prices[sell_day]) {
              auto profit = prices[sell_day] - prices[i];
              if (i >= 2) {
                  int max_profit2 = 0;
                  for (int k = i - 1; k >= 1; k--) {
                      if (record.end() == record.find(k)) {
                          auto profit2 = _maxProfit(prices, k, record);
                          record[k] = profit2;
                      }
                      max_profit2 = record[k] > max_profit2 ? record[k] : max_profit2;
                  }
                  profit += max_profit2;
              }
              max_profit = profit > max_profit ? profit : max_profit;
          }
      }

      return max_profit;
  }

  int maxProfit0(vector<int> &prices) {
    unordered_map<int, int> record;
      int max_profit = 0;
      for (int i = 1; i < prices.size(); i++) {
          auto profit = _maxProfit(prices, i, record);
          max_profit = profit > max_profit ? profit : max_profit;
      }

      return max_profit;
  }
};

int main() {
    Solution s;
    vector<int> prices = {2, 2, 5};
    cout << s.maxProfit(prices);
    return 0;
}