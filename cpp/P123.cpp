/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   27 December 2020 15:58
 * @brief  从discussion可以观察到，极大值和极小值点一定是交替出现的
 * 第二个事实，对于任意两个极值点对，多次交易一定比单次交易利润更大（不然不会出现起伏，从图上可以看出）
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
  // O(n)版本
  int maxProfit(vector<int> &prices) {
      int n = prices.size();
      if (n <= 1) {
          return 0;
      }
      int ddl_min[n];
      ddl_min[0] = prices[0];
      for (int i = 1; i < n; i ++) {
          ddl_min[i] = prices[i] < ddl_min[i - 1] ? prices[i] : ddl_min[i - 1];
      }
      int since_max[n];
      since_max[n - 1] = prices[n - 1];  // 从第i天起的最高价
      for (int i = n - 2; i >= 0; i --) {
          since_max[i] = prices[i] > since_max[i + 1] ? prices[i] : since_max[i + 1];
      }

      int ddl_profit[n];  // 直到第i天的最大利润（一次）
      ddl_profit[0] = 0;
      for (int i = 1; i < n; i ++) {
          auto profit = prices[i] - ddl_min[i - 1];
          ddl_profit[i] = profit > ddl_profit[i - 1] ? profit : ddl_profit[i - 1];
      }

      int since_profit[n];
      since_profit[n - 1] = 0;
      for (int i = n - 2; i >= 0; i --) {
          auto profit = since_max[i + 1] - prices[i];
          since_profit[i] = profit > since_profit[i + 1] ? profit : since_profit[i + 1];
      }

      int max_profit = 0;
      for (int i = 0; i < n; i ++) {
          int profit = ddl_profit[i];
          if (i + 1 < n) {
              profit += since_profit[i + 1];
          }
          max_profit = profit > max_profit ? profit : max_profit;
      }

      return max_profit;
  }
      // 极值版本；这个版本也TL啊
  int maxProfit0(vector<int> &prices) {
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

      vector<int> l_profits(n, 0);  // 0 ~ kth天的单次交易最大利润
      vector<int> r_profits(n, 0);
      for (int i = 0; i < n; i++) {
          if (-1 == point_types[i]) {
              for (int j = i + 1; j < n; j++) {
                  if (1 == point_types[j]) {
                      auto profit = prices[j] - prices[i];
                      l_profits[j] = profit > l_profits[j] ? profit : l_profits[j];
                      for (int k = j + 1; k < n; k++) {
                          l_profits[k] = l_profits[j] > l_profits[k] ? l_profits[j] : l_profits[k];
                      }
                      r_profits[i] = profit > r_profits[i] ? profit : r_profits[i];
                      for (int k = i - 1; k >= 0; k--) {
                          r_profits[k] = r_profits[i] > r_profits[k] ? r_profits[i] : r_profits[k];

                      }
                  }
              }
          }
      }
      int max_profit = 0;
      for (int k = 0; k < n; k++) {
          // cout << l_profits[k] << ", k=" << k << ", " << r_profits[k + 1] << "\n";
          int profit = 0;
          if (k >= 1) {
              profit += l_profits[k];
          }
          if (k + 1 <= n - 2) {
              profit += r_profits[k + 1];
          }
          max_profit = profit > max_profit ? profit : max_profit;
      }

      return max_profit;
  }
};

int main() {
    Solution s;
    vector<int> prices = {7,6,4,3,1};
    cout << s.maxProfit(prices);
    return 0;
}