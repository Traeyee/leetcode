/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-27 17:19
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
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));  // TODO: 初始化值
        // dp[i][j]: 引爆i~j

        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         for (int k = i + 1; k < j; i++) {  // TODO: 边界
        //             dp[i][j] = dp[i][k - 1] * nums[k] * dp[k + 1][j];
        //         }
        //     }
        // }

        return dp[0][n - 1];
    }
};