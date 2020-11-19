/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   19 November 2020 16:14
 * @brief  leetcode好像有bug，已发thread
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<vector<int>> _combinationSum3(int k, int n, int offset) {
      vector<vector<int>> result(0);

      if (1 == k && offset <= n){
          vector<int> tmp = {n};
          result.emplace_back(tmp);
          return result;
      }

      if (k >= n || offset >= n) {
          return result;
      }

      for (int x = offset; x < n; x++) {
          auto rst = _combinationSum3(k - 1, n - x, x + 1);
          if (rst.empty()) {
              continue;
          }
          for (auto & comb : rst) {
              comb.emplace_back(x);
              result.emplace_back(comb);
          }
      }
      return result;
  }
  vector<vector<int>> combinationSum3(int k, int n) {
      return _combinationSum3(k, n, 1);
  }
};

int main() {
    Solution s;
    for (const auto &comb : s.combinationSum3(2, 18)) {
        for (const auto &num : comb) {
            cout << num << ",";
        }
        cout << "\n";
    }
    return 0;
}