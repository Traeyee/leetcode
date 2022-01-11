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
        int n = nums.size();
        vector<int> dp_p(n, 1), dp_n(n, 1);
        bool has_pos_res = false;
        if (nums[0] > 0) {
            dp_p[0] = nums[0];
            has_pos_res = true;
        } else {
            dp_n[0] = nums[0];
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                has_pos_res = true;
                if (dp_p[i - 1] > 0) {
                    dp_p[i] = nums[i] * dp_p[i - 1];
                } else {
                    dp_p[i] = nums[i];
                }
                if (dp_n[i - 1] < 0) {
                    dp_n[i] = nums[i] * dp_n[i - 1];
                }
            } else if (nums[i] < 0) {
                if (dp_p[i - 1] > 0) {
                    dp_n[i] = nums[i] * dp_p[i - 1];
                } else {
                    dp_n[i] = nums[i];
                }
                if (dp_n[i - 1] < 0) {
                    dp_p[i] = nums[i] * dp_n[i - 1];
                    has_pos_res = true;
                }
            } else {
                dp_p[i] = 0;
                dp_n[i] = 0;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << "# " << "p: " << dp_p[i] << ", n: " << dp_n[i] << '\n';
        // }

        if (!has_pos_res) {
            return *max_element(dp_n.begin(), dp_n.end());
        }
        return *max_element(dp_p.begin(), dp_p.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {2, 3, -2, 4};
    cout << sol.maxProduct(nums) << "\n";

    nums = {-2, 0, -1};
    cout << sol.maxProduct(nums) << "\n";

    nums = {-2, 3, -4};
    cout << sol.maxProduct(nums) << "\n";

    nums = {-2};
    cout << sol.maxProduct(nums) << "\n";

    nums = {-3, -1, -1};
    cout << sol.maxProduct(nums) << "\n";

    return 0;
}