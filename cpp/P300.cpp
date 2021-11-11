/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-02 18:13
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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    int new_len = dp[i] + 1;
                    // cout << "#update:[" << i << "][" << j << "]" << dp[j];
                    dp[j] = new_len > dp[j] ? new_len : dp[j];
                    // cout << "-->" << dp[j] << "\n";
                }
            }
        }

        int max_len = 0;
        for (const auto& len : dp) {
            max_len = len > max_len ? len : max_len;
        }

        return max_len;
    }
};