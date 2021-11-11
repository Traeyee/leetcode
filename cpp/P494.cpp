/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-02 20:12
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp;
        for (size_t i = 0; i < n; i++) {
            unordered_map<int, int> tmp;
            dp.emplace_back(tmp);
        }
        dp[0][-nums[0]]++;
        dp[0][nums[0]]++;

        for (int i = 0; i < n - 1; i++) {
            for (const auto& p : dp[i]) {
                int target1 = p.first - nums[i + 1];
                int target2 = p.first + nums[i + 1];
                dp[i + 1][target1] += p.second;
                dp[i + 1][target2] += p.second;
            }
        }

        for (const auto& p : dp[n - 1]) {
            cout << "#" << p.first << ":" << p.second << "\n";
        }

        return dp[n - 1][target];
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    int target = 1;
    Solution s;
    cout << s.findTargetSumWays(nums, target) << "\n";
    return 0;
}