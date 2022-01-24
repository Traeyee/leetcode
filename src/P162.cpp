/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-24 15:59
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& nums, int l, int r) {
        if (l > r) {
            return -1;
        }
        int mid = (l + r) / 2;

        if (mid - 1 >= 0 && nums[mid - 1] >= nums[mid]) {
            int idx = findPeakElement(nums, l, mid - 1);
            if (idx >= 0) {
                return idx;
            }
        }

        if (mid + 1 < nums.size() && nums[mid] <= nums[mid + 1]) {
            int idx = findPeakElement(nums, mid + 1, r);
            if (idx >= 0) {
                return idx;
            }
        }

        return mid;
    }
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 2, 3, 1};
    cout << sol.findPeakElement(nums) << "\n";

    nums = {1, 2, 1, 3, 5, 6, 4};
    cout << sol.findPeakElement(nums) << "\n";

    return 0;
}