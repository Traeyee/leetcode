/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-03 18:37
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
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int min1, min2;
        if (nums[0] < nums[1]) {
            min1 = nums[0];
            min2 = nums[1];
        } else {
            min1 = nums[1];
            min2 = ~(1 << 31);
        }
        for (int i = 2; i < n; i++) {
            // cout << i << ": " << min1 << " < " << min2 << '\n';
            if (min2 < nums[i]) {
                return true;
            } else if (nums[i] < min1) {
                min1 = nums[i];
            } else if (min1 < nums[i]) {
                min2 = nums[i];
            }
        }
        return false;
    }
    bool increasingTriplet0(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        bool found2 = false;
        int min1 = nums[0], min2;

        for (int i = 1; i < n; i++) {
            if (found2) {
                if (min2 < nums[i]) {
                    return true;
                } else if (min1 < nums[i] && nums[i] < min2) {
                    min2 = nums[i];
                    if (nums[i - 1] < min1) {
                        min1 = nums[i - 1];
                    }
                } else if (nums[i - 1] < min1 && nums[i] < min2) {
                    min1 = nums[i - 1];
                    min2 = nums[i];
                }
            } else {
                if (nums[i - 1] < min1 && nums[i - 1] < nums[i]) {
                    min1 = nums[i - 1];
                    min2 = nums[i];
                    found2 = true;
                } else if (min1 < nums[i]) {
                    min2 = nums[i];
                    found2 = true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 2, 3, 4, 5};
    cout << sol.increasingTriplet(nums) << '\n';

    nums = {5, 4, 3, 2, 1};
    cout << sol.increasingTriplet(nums) << '\n';

    nums = {2, 1, 5, 0, 4, 6};
    cout << sol.increasingTriplet(nums) << '\n';

    nums = {20, 100, 10, 12, 5, 13};
    cout << sol.increasingTriplet(nums) << '\n';

    nums = {1, 0, -1, 0, 100};
    cout << sol.increasingTriplet(nums) << '\n';

    nums = {1, 6, 2, 5, 1};
    cout << sol.increasingTriplet(nums) << '\n';

    nums = {1, 0, 0, 1};
    cout << sol.increasingTriplet(nums) << '\n';

    return 0;
}