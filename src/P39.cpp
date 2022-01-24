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
  void _combinationSum(vector<int> &candidates, int target, vector<int> &combination, vector<vector<int>> &solutions, unordered_set<string> &hashset) {
      for (const auto &x : candidates) {
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
              _combinationSum(candidates, target - x, combination, solutions, hashset);
              combination.pop_back();
          }
      }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
      vector<vector<int> > solutions;
      vector<int> combination;
      unordered_set<string> hashset;
      _combinationSum(candidates, target, combination, solutions, hashset);
      return solutions;
  }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    Solution s;
    s.combinationSum(candidates, 7);
    return 0;
}