/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-09 18:38
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        stack<pair<int, int>> stk;
        stk.emplace(0, nums.size() - 1);

        int start = n, end = -1;
        while (stk.size() > 0) {
            int l = stk.top().first, r = stk.top().second;
            stk.pop();
            if (l > r) {
                continue;
            }
            int mid = (r - l) / 2 + l;
            if (target == nums[mid]) {
                start = mid < start ? mid : start;
                end = mid > end ? mid : end;
                stk.emplace(mid + 1, r);
                stk.emplace(l, mid - 1);
            } else if (target < nums[mid]) {
                stk.emplace(l, mid - 1);
            } else {
                stk.emplace(mid + 1, r);
            }
        }
        if (start == n) {
            start = -1;
        }
        return {start, end};
    }
    vector<int> searchRange0(vector<int>& nums, int target) {
        int start = -1, end = -1;
        int l = 0, r = nums.size() - 1;
        // 先找start
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid - 1 < 0) {
                    start = mid;
                    break;
                } else if (nums[mid - 1] < target) {
                    start = mid;
                    break;
                }
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (-1 == start) {
            return {-1, -1};
        }

        l = start, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid + 1 >= nums.size()) {
                    end = mid;
                    break;
                } else if (target < nums[mid + 1]) {
                    end = mid;
                    break;
                }
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return {start, end};
    }
};

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    vector<int> nums;
    int target;
    vector<int> res;

    nums = {5, 7, 7, 8, 8, 10}, target = 8;
    res = sol.searchRange(nums, target);
    print_vector(res);

    nums = {5, 7, 7, 8, 8, 10}, target = 6;
    res = sol.searchRange(nums, target);
    print_vector(res);

    nums = {}, target = 0;
    res = sol.searchRange(nums, target);
    print_vector(res);

    return 0;
}