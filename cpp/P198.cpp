#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        if (0 == n) {
            return 0;
        } else if (1 == n) {
            return nums[0];
        }

        int dp[n];
        dp[0] = nums[0];
        dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        for (size_t i = 2; i < n; i++) {
            int x1 = dp[i - 2] + nums[i];
            int x2 = dp[i - 1];
            dp[i] = x1 > x2 ? x1 : x2;
        }

        return dp[n - 1];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    cout << s.rob(nums) << "\n";

    nums = {2, 7, 9, 3, 1};
    cout << s.rob(nums) << "\n";

    return 0;
}