/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-07 17:10
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
    bool foo(vector<int>& nums, vector<int>& sums, int idx, int target) {
        int n = nums.size(), k = sums.size();
        if (idx == n) {
            for (int i = 0; i < k - 1; i++) {
                if (sums[i] != sums[i + 1]) {
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (sums[i] + nums[idx] > target) {
                continue;
            }
            
            sums[i] += nums[idx];
            if (foo(nums, sums, idx + 1, target)) {
                return true;
            }
            sums[i] -= nums[idx];
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (const auto& ele : nums) {
            sum += ele;
        }
        if (0 != sum % k) {
            return false;
        }

        int target = sum / k;
        vector<int> sums(k, 0);
        return foo(nums, sums, 0, target);
    }

    bool _canPartitionKSubsets(vector<int>& nums, vector<bool>& used,
                               int n_used, int tmp_target, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            cout << "# " << n_used << "[" << tmp_target << "]:(" << i << ")"
                 << nums[i] << "(" << used[i] << ")"
                 << "\n";

            if (!used[i]) {
                if (nums[i] == tmp_target) {
                    if (n_used + 1 == n) {
                        cout << "#ok\n";
                        return true;
                    } else {
                        used[i] = true;
                        return _canPartitionKSubsets(nums, used, n_used + 1,
                                                     target, target);
                    }
                } else if (nums[i] < tmp_target) {
                    used[i] = true;
                    return _canPartitionKSubsets(nums, used, n_used + 1,
                                                 tmp_target - nums[i], target);
                }
            }
        }

        return false;
    }

    // 错的
    bool canPartitionKSubsets0(vector<int>& nums, int k) {
        int sum = 0;
        for (const auto& ele : nums) {
            sum += ele;
        }
        if (0 != sum % k) {
            return false;
        }

        int target = sum / k;
        vector<bool> used(nums.size(), false);
        return _canPartitionKSubsets(nums, used, 0, target, target);
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int k;

    nums = {4, 3, 2, 3, 5, 2, 1};
    k = 4;
    cout << s.canPartitionKSubsets(nums, k) << "\n";

    nums = {1, 2, 3, 4};
    k = 3;
    cout << s.canPartitionKSubsets(nums, k) << "\n";

    nums = {1, 1, 1, 1, 2, 2, 2, 2};
    k = 4;
    cout << s.canPartitionKSubsets(nums, k) << "\n";

    nums = {3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269};
    k = 5;
    cout << s.canPartitionKSubsets(nums, k) << "\n";

    return 0;
}