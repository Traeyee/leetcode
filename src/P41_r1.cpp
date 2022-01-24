/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-28 10:04
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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
    // 置负法清晰版
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool has_1 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                has_1 = true;
            } else if (nums[i] < 0) {
                nums[i] = 0;
            }
        }
        if (!has_1) {
            return 1;
        }

        // 此时必含1
        for (int i = 0; i < n; i++) {
            int idx;
            if (nums[i] < 0) {
                idx = -nums[i] - 1;
            } else {
                idx = nums[i] - 1;
            }
            if (0 <= idx && idx < n) {
                if (nums[idx] > 0) {
                    nums[idx] = -nums[idx];
                } else if (nums[idx] == 0) {
                    nums[idx] = -1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
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

    nums = {1, 2, 0};
    cout << sol.firstMissingPositive(nums) << "\n";

    nums = {3, 4, -1, 1};
    cout << sol.firstMissingPositive(nums) << "\n";

    nums = {7, 8, 9, 11, 12};
    cout << sol.firstMissingPositive(nums) << "\n";

    nums = {1, 2, 6, 3, 5, 4};
    cout << sol.firstMissingPositive(nums) << "\n";

    return 0;
}