/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   27 December 2020 15:34
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
  void _combine(int n, int k, int offset, vector<int> &combination, vector<vector<int> > &combinations) {
      if (0 == k) {
          combinations.push_back(combination);
          return;
      }

      for (int i = offset; i <= n; i++) {
          combination.push_back(i);
          _combine(n, k - 1, i + 1, combination, combinations);
          combination.pop_back();
      }
  }

  vector<vector<int>> combine(int n, int k) {
      vector<int> combination;
      vector<vector<int> > combinations;
      _combine(n, k, 1, combination, combinations);

      return combinations;
  }
};

