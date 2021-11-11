#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Time Limit Exceeded
class Solution0 {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> sum;

        int cnt = 0;
        for (size_t i = 0; i < n; i++) {
            vector<int> tmp;
            sum.emplace_back(tmp);
            sum[i].emplace_back(nums[i]);
            if (sum[i][0] == k) {
                    cnt++;
                }
            for (size_t j = i + 1; j < n; j++) {
                int l = j - i;
                sum[i].emplace_back(sum[i][l - 1] + nums[j]);
                if (sum[i][l] == k) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};