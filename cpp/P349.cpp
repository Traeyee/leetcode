/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   12 November 2020 22:37
 * @brief  
 */
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
      set<int> set1;
      for (const auto &num : nums1) {
          set1.insert(num);
      }
      vector<int> ret;
      set<int> set2;
      for (const auto &num : nums2) {
          if (set1.find(num) != set1.end() && set2.find(num) == set2.end()) {
              ret.emplace_back(num);
              set2.insert(num);
          }
      }
      return ret;
  }
};
int main() {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    Solution s;
    for (auto & e : s.intersection(nums1, nums2)) {
        cout << e << ", ";
    }

    return 0;
}