/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-30 15:37
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
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = nums[i] - 1;
            if (idx != i && nums[idx] == nums[i]) {
                return nums[i];
            }
            swap(nums[idx], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i + 1 != nums[i]) {
                return nums[i];
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(nums) << "\n";

    nums = {3, 1, 3, 4, 2};
    cout << sol.findDuplicate(nums) << "\n";

    nums = {1, 1};
    cout << sol.findDuplicate(nums) << "\n";

    nums = {1, 1, 2};
    cout << sol.findDuplicate(nums) << "\n";

    nums = {8,  7,  1, 10, 17, 15, 18, 11, 16, 9,
            19, 12, 5, 14, 3,  4,  2,  13, 18, 18};
    cout << sol.findDuplicate(nums) << "\n";

    return 0;
}