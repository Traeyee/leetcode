/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-11 21:06
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
// 最暴力方法当然是bool数组，遇到置true，再遍历返回false的那个即可，时间O(n)，空间O(n)
// Follow up: 空间O(1)
// 思路当然是怎么巧妙地表示bool了
// 想到了，相应位置置负即可
class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int idx40 = -1;
        for (int i = 0; i < n; i++) {
            int i2 = nums[i] >= 0 ? nums[i] : -nums[i];
            if (i2 < n) {
                if (0 == nums[i2]) {
                    idx40 = i2;
                } else {
                    nums[i2] *= -1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            } else if (0 == nums[i] && i != idx40) {
                return i;
            }
        }
        return n;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {3, 0, 1};
    cout << sol.missingNumber(nums) << "\n";

    nums = {0, 1};
    cout << sol.missingNumber(nums) << "\n";

    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << sol.missingNumber(nums) << "\n";

    nums = {0};
    cout << sol.missingNumber(nums) << "\n";

    return 0;
}