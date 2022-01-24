/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   14 November 2020 10:39
 * @brief  
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
      vector<int> lp(nums.size(), 1);
      vector<int> rp(nums.size(), 1);

      int product = 1;
      for (int i = 0; i < nums.size(); i++) {
          product *= nums[i];
          lp[i] = product;
      }
      product = 1;
      for (int i = nums.size() - 1; i >= 0; i--) {
          product *= nums[i];
          rp[i] = product;
      }

      vector<int> ret;
      for (int i = 0; i < nums.size(); i++) {
          product = 1;
          if (i - 1 >= 0) {
              product *= lp[i - 1];
          }
          if (i + 1 <= nums.size() - 1) {
              product *= rp[i + 1];
          }
          ret.emplace_back(product);
      }
      return ret;
  }
  // 缩减版
  vector<int> productExceptSelf2(vector<int> &nums) {
      vector<int> rst(nums.size(), 1);
      int product = 1;
      for (int i = 0; i < nums.size(); i++) {
          rst[i] *= product;
          product *= nums[i];
      }
      product = 1;
      for (int i = nums.size() - 1; i >= 0; i--) {
          rst[i] *= product;
          product *= nums[i];
      }
      return rst;
  }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    for (const auto &x : s.productExceptSelf(nums)) {
        cout << x << "\n";
    }
    return 0;
}