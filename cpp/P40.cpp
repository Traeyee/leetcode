/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   25 December 2020 14:04
 * @brief  可试试最简单的递归子问题
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void _combinationSum(vector<int> &candidates, int target, vector<bool> used, vector<int> &combination, vector<vector<int>> &solutions, unordered_set<string> &hashset) {
      for (int i = 0; i < candidates.size(); i++) {
          if (used[i]) {
              continue;
          }

          auto x = candidates[i];
          if (x == target) {
              combination.emplace_back(x);

              // calc hash key
              auto tmp = combination;
              sort(tmp.begin(), tmp.end());
              string key;
              for (const auto &p : tmp) {
                  key += to_string(p);
                  key.push_back('-');
              }
              key.pop_back();

              // check existence
              if (hashset.end() == hashset.find(key)) {
                  solutions.push_back(combination);
                  hashset.insert(key);
              }

              combination.pop_back();
          } else if (x < target) {
              combination.emplace_back(x);
              used[i] = true;
              _combinationSum(candidates, target - x, used, combination, solutions, hashset);
              used[i] = false;
              combination.pop_back();
          }
      }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
      vector<vector<int> > solutions;
      int sum = 0;
      for (const auto & x : candidates) {
          sum += x;
      }
      if (sum >= target) {
          vector<int> combination;
          unordered_set<string> hashset;
          vector<bool> used(candidates.size(), false);
          _combinationSum(candidates, target, used, combination, solutions, hashset);
      }

      return solutions;
  }
};

int main() {
    vector<int> candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution s;
    s.combinationSum(candidates, 27);
    return 0;
}