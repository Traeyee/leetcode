/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   27 December 2020 09:23
 * @brief  可以看成爬楼梯问题
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
  // 减少重复运算
  int _combinationSum4(vector<int> &nums, int target, unordered_map<int, int> &record) {
      if (0 == target) {
          return 1;
      }

      int y = 0;

      for (auto num : nums) {
          if (num <= target) {
              auto target2 = target - num;
              if (record.end() == record.find(target2)) {
                  record[target2] = _combinationSum4(nums, target2, record);
              }
              y += record[target2];
          }
      }

      return y;
  }

  // 先改成递归试试，巨慢；可能有bug
  int combinationSum4_1(vector<int> &nums, int target) {
      stack<int> indices;
      indices.push(0);
      stack<int> targets;
      targets.push(target);

      int num_solution = 0;
      while (!indices.empty()) {
          auto idx = indices.top();
          indices.pop();
          auto x = nums[idx];
          auto y = targets.top();
          targets.pop();
          if (0 == y) {
              num_solution += 1;
              continue;
          }

          if (num_solution >= 181997601) {
              cout << "here\n";
              exit(1);
          }
          cout << num_solution << "\n";
          cout << x << ", " << y << "\n";

          if (x <= y) {
              idx++;
              if (idx < nums.size()) {
                  indices.push(idx);
                  targets.push(y);
              }
              indices.push(0);
              targets.push(y - x);
          }
      }

      return num_solution;
  }

  // 原始的做法，可用动态规划优化一下
  int combinationSum4_0(vector<int> &nums, int target) {
      if (0 == target) {
          return 1;
      }

      int y = 0;

      for (auto num : nums) {
          if (num <= target) {
              y += combinationSum4_0(nums, target - num);
          }
      }

      return y;
  }

  int combinationSum4(vector<int> &nums, int target) {
      unordered_map<int, int> record;
      return _combinationSum4(nums, target, record);
  }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    cout << s.combinationSum4(nums, 32);
}