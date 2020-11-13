/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   13 November 2020 09:21
 * @brief  
 */
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
      unordered_map<int, int> counter;
      for (const auto &x : nums) {
          if (counter.find(x) == counter.end()) {
              counter[x] = 0;
          }
          counter[x]++;
      }

      typedef pair<int, int> intp;
      auto cmp = [](intp &p1, intp &p2) {
        return p1.second < p2.second;
      };
      priority_queue<intp, vector<intp>, decltype(cmp)> items(cmp);
      for (const auto &p : counter) {
          items.push(p);
      }

      vector<int> ret;
      while (!items.empty()) {
          auto p = items.top();
          items.pop();
          ret.emplace_back(p.first);
          if (ret.size() == k) {
              break;
          }
      }

      return ret;
  }
};

int main() {
    vector<int> nums = {3, 0, 1, 0};
    Solution s;
    for (const auto & x : s.topKFrequent(nums, 3)) {
        cout << x << ", ";
    }

    return 0;
}