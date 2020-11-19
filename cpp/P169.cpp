/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   14 November 2020 17:42
 * @brief  
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
      // 摩尔投票法
      int focus;
      int cnt = 0;
      for (const auto &x : nums) {
          if (focus == x) {
              cnt++;
          } else if (cnt > 0) {
              cnt--;
          } else {
              cnt++;
              focus = x;
          }
      }
      return focus;
  }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution s;
    cout << s.majorityElement(nums);
    return 0;
}
