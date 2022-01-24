/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   12 November 2020 22:56
 * @brief  
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
 public:
  void foo(vector<bool> &status, int k, vector<int>& nums, vector<vector<int>>& ret) {
      if (k == status.size()) {
          vector<int> ret1;
          for (size_t i = 0; i < status.size(); i++) {
              if (status[i]) {
                  ret1.emplace_back(nums[i]);
              }
          }
          ret.emplace_back(ret1);
          return;
      }
      status[k] = true;
      foo(status, k + 1, nums, ret);
      status[k] = false;
      foo(status, k + 1, nums, ret);
  }
  vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ret;
      vector<bool> status(nums.size(), true);
      foo(status, 0, nums, ret);
      return ret;
  }

  vector<vector<int>> subsets2(vector<int>& nums) {
// TODO
      vector<vector<int>> ret;
      stack<pair<int, bool>> stk;
      vector<int> status(nums.size(), true);

      // key: 通过一个状态变量控制对stack的操作
      return ret;
  }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    for (const auto & subset : s.subsets(nums)) {
        for (const auto & e : subset) {
            cout << e << ", ";
        }
        cout << "\n";
    }
    return 0;
}