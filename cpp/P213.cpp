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
    int _rob(vector<int>& nums) {
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

    int rob(vector<int>& nums) {
        size_t n = nums.size();
        if (0 == n) {
            return 0;
        } else if (1 == n) {
            return nums[0];
        } else if (2 == n) {
            return nums[1] > nums[0] ? nums[1] : nums[0];
        }

        // 教训：vector操作前必先预先reserve分配空间，血泪教训
        // 情况一：第n间房不偷
        vector<int> nums1;
        nums1.reserve(n);
        // cout << n << "," << nums1.size() << "," << nums1.capacity() << "\n";
        // cout << n - 1 << "\n";
        nums1.insert(nums1.end(), nums.begin(), nums.end() - 1);
        // for (size_t i = 0; i < nums1.size(); i++) {
        //     cout << "#" << i << ":" << nums1[i] << "\n";
        // }
        // cout << n << "," << nums1.size() << "," << nums1.capacity() << "\n";
        int x1 = _rob(nums1);

        // 情况二：第n间房偷
        nums1.clear();
        nums1.reserve(n);
        // cout << nums1.size() << "\n";
        nums1.insert(nums1.end(), nums.begin() + 1, nums.end() - 2);
        // cout << nums1.size() << "\n";
        int x2 = _rob(nums1) + nums[n - 1];

        cout << x1 << "," << x2 << "\n";
        return x1 > x2 ? x1 : x2;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    cout << s.rob(nums) << "\n";

    nums = {2, 3, 2};
    cout << s.rob(nums) << "\n";

    nums = {1, 2, 1, 1};
    cout << s.rob(nums) << "\n";

    return 0;
}