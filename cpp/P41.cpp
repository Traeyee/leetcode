/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-14 21:15
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
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool has_1 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = 0;
            } else if (1 == nums[i]) {
                has_1 = true;
            }
        }
        if (!has_1) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0 && nums[i] != -1) {  // 之前必定正数
                int v = nums[i] > 0 ? nums[i] : -nums[i];
                int idx = v - 1;
                // cout << "# " << i << " let " << idx << ": " << nums[idx];
                if (idx < n) {
                    if (0 == nums[idx]) {
                        nums[idx] = -1;
                    } else {
                        nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
                    }
                }
                // cout << " --> " << nums[idx] << "\n";
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << i << ": " << nums[i] << "\n";
        // }

        for (int i = 1; i < n; i++) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // nums = {1, 2, 0};
    // cout << sol.firstMissingPositive(nums) << "\n";

    // nums = {3, 4, -1, 1};
    // cout << sol.firstMissingPositive(nums) << "\n";

    // nums = {7, 8, 9, 11, 12};
    // cout << sol.firstMissingPositive(nums) << "\n";

    nums = {1, 2, 6, 3, 5, 4};
    cout << sol.firstMissingPositive(nums) << "\n";

    return 0;
}