/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-20 11:47
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
    int maxProduct(vector<int>& nums) {
        vector<int> dp_p, dp_n;
        int p_idx0 = -1, n_idx0 = -1;
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            if (ele > 0) {
                dp_p.emplace_back(ele);
                dp_n.emplace_back(0);
                if (-1 == p_idx0) {
                    p_idx0 = i;
                }
            } else if (ele < 0) {
                dp_p.emplace_back(0);
                dp_n.emplace_back(ele);
                if (-1 == n_idx0) {
                    n_idx0 = i;
                }
            } else {
                dp_p.emplace_back(0);
                dp_n.emplace_back(0);
            }
        }
        if (-1 == p_idx0 && -1 == n_idx0) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                dp_p[i] = nums[i];
                if (i - 1 >= p_idx0) {
                    dp_p[i] = nums[i] * dp_p[i - 1] > nums[i]
                                  ? nums[i] * dp_p[i - 1]
                                  : nums[i];
                }
                if (i - 1 >= n_idx0) {
                    dp_n[i] = nums[i] * dp_n[i - 1] < nums[i]
                                  ? nums[i] * dp_n[i - 1]
                                  : nums[i];
                }
            } else {
                dp_n[i] = nums[i];
                if (i - 1 >= n_idx0) {
                    dp_p[i] = nums[i] * dp_n[i - 1] > nums[i]
                                  ? nums[i] * dp_n[i - 1]
                                  : nums[i];
                }
                if (i - 1 >= p_idx0) {
                    dp_n[i] = nums[i] * dp_p[i - 1] < nums[i]
                                  ? nums[i] * dp_p[i - 1]
                                  : nums[i];
                }
            }
        }

        cout << "# " << p_idx0 << ", " << n_idx0 << "\n";
        for (int i = 0; i < nums.size(); i++) {
            cout << "## " << i << ": ";
            if (i >= p_idx0) {
                cout << "P: " << dp_p[i] << ", ";
            }
            if (i >= n_idx0) {
                cout << "N: " << dp_n[i];
            }
            cout << "\n";
        }

        if (-1 != p_idx0) {
            return *max_element(dp_p.begin() + p_idx0, dp_p.end());
        }
        return *max_element(dp_n.begin() + n_idx0, dp_n.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // nums = {2, 3, -2, 4};
    // cout << sol.maxProduct(nums) << "\n";

    // nums = {-2, 0, -1};
    // cout << sol.maxProduct(nums) << "\n";

    // nums = {-2, 3, -4};
    // cout << sol.maxProduct(nums) << "\n";

    // nums = {-2};
    // cout << sol.maxProduct(nums) << "\n";

    nums = {-3, -1, -1};
    cout << sol.maxProduct(nums) << "\n";

    return 0;
}