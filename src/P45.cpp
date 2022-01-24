/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-06 09:08
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
    int jump(vector<int>& nums) {
        int n = nums.size();
        int THE_MAX = pow(10, 5);
        vector<int> dp(n, THE_MAX);
        dp[0] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i + j] = min({dp[i] + 1, dp[i + j]});
            }
        }

        return dp[n - 1];
    }
};