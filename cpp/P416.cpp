/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-03 16:36
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
    bool canPartition(vector<int>& nums) {
        int sum1 = accumulate(nums.begin(), nums.end(), 0);
        if (1 == sum1 % 2) {
            return false;
        }

        int target = sum1 / 2;
        int n = nums.size();
        // int dp[n + 1][target + 1];
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= target; w++) {
                if (w < nums[i - 1]) {
                    dp[i][w] = dp[i - 1][w];
                } else {
                    dp[i][w] = max({dp[i - 1][w],
                                    dp[i - 1][w - nums[i - 1]] + nums[i - 1]});
                }
                if (dp[i][w] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 5, 11, 5};
    cout << s.canPartition(nums) << "\n";

    nums = {1, 2, 3, 5};
    cout << s.canPartition(nums) << "\n";

    return 0;
}