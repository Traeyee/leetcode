/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-14 15:25
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
    pair<int, int> search(vector<int>& nums, int l, int r, int target) {
        // TODO: base case

        int n = nums.size();
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return {-1, mid};
        }

        if (mid - 1 < 0 && mid + 1 < n) {
            return {mid, -1};
        } else if (mid - 1 < 0) {
            if (nums[mid] > nums[mid + 1]) {
                return {mid, -1};
            }
        } else if (mid + 1 < n) {
        } else {
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return {mid, -1};
            }
            auto res1 = search(nums, l, mid - 1, target);
            auto res2 = search(nums, mid + 1, r, target);
        }
        return {-1, -1};
    }

    int search(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return -1;
        }

        int n = nums.size();
        int mid = (l + r) / 2;

        if (mid - 1 < 0 && mid + 1 >= n) {
            return mid;
        } else if (mid - 1 < 0 && mid + 1 < n) {
            if (nums[mid] > nums[mid + 1]) {
                return mid;
            }
        } else if (mid - 1 >= 0 && mid + 1 >= n) {
            if (nums[mid - 1] < nums[mid]) {
                return mid;
            }
        } else if (mid - 1 >= 0 && mid + 1 < n) {
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
        }
        int p1 = search(nums, l, mid);
        if (-1 != p1) {
            return p1;
        }
        int p2 = search(nums, mid + 1, r);
        return p2;
    }

    int binary_search(vector<int>& nums, int l, int r, int target) {
        // cout << "# here " << l << "-" << r << "\n";
        if (l >= r) {
            return -1;
        }

        int n = nums.size();
        int mid = (l + r) / 2;
        // cout << "# " << l << "-" << mid << "-" << r << "\n";

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            return binary_search(nums, l, mid, target);
        }
        return binary_search(nums, mid + 1, r, target);
    }

    int search(vector<int>& nums, int target) {
        // 先二分找到k，TODO：途中有k返k
        // 再确定区间，再找target
        if (target == nums[0]) {
            return 0;
        }

        int n = nums.size();
        int idx = search(nums, 0, nums.size());
        int k = n - idx - 1;
        // cout << "# " << idx << ", " << k << "\n";

        if (target > nums[0]) {
            return binary_search(nums, 1, idx + 1, target);
        }
        // cout << "#here\n";
        return binary_search(nums, idx + 1, n, target);
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int target;

    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    cout << sol.search(nums, target) << "\n";

    target = 3;
    cout << sol.search(nums, target) << "\n";

    nums = {1};
    target = 0;
    cout << sol.search(nums, target) << "\n";

    nums = {1, 3};
    target = 3;
    cout << sol.search(nums, target) << "\n";

    nums = {3, 1};
    target = 1;
    cout << sol.search(nums, target) << "\n";

    nums = {2, 3, 4, 5, 1};
    target = 1;
    cout << sol.search(nums, target) << "\n";

    return 0;
}