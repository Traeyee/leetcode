/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-10-30 19:32
 * @brief  Time Limit Exceeded，得用二分法优化一下
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
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
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end()),
            r = accumulate(nums.begin(), nums.end(), 0);
        int min_limit = r;
        while (l <= r) {
            int sum_limit = (r - l) / 2 + l;
            int cur_sum = 0, subarr_cnt = 1;
            for (int x : nums) {
                if (cur_sum + x > sum_limit) {
                    subarr_cnt++;
                    cur_sum = x;
                } else {
                    cur_sum += x;
                }
            }

            if (subarr_cnt <= m) {
                // 太大了，可以缩
                r = sum_limit - 1;
                min_limit = sum_limit < min_limit ? sum_limit : min_limit;
            } else {
                l = sum_limit + 1;
            }
        }

        return min_limit;
    }
    int least_split(vector<int>& nums, int sum_limit) {
        // 注意到一个事实，从前面开始算起，在sum_limit下如果前面的子区间能尽量多地吞下元素，对后面越有利
        // 不存在前面多吞了，后面就不是最优的可能，因为 0 <= nums[i] <= 106
        int sum = 0, cnt = 1;
        for (const auto& ele : nums) {
            if (sum + ele > sum_limit) {
                sum = ele;
                cnt++;
            } else {
                sum += ele;
            }
        }
        return cnt;
    }
    int splitArray__TL(vector<int>& nums, int m) {
        int max_sum = 0;
        for (const auto& ele : nums) {
            max_sum += ele;
        }
        int min_sum = 0;
        for (const auto& ele : nums) {
            if (ele > min_sum) {
                min_sum = ele;
            }
        }
        if (max_sum == min_sum) {
            return min_sum;
        }

        int min_max_sum = max_sum, lbound = min_sum, rbound = max_sum + 1;
        while (lbound < rbound) {
            int sum_limit = (lbound + rbound) / 2;
            // n_split会随着sum_limit减小而增大
            int n_split = least_split(nums, sum_limit);
            // cout << "#" << n_split << ", " << sum_limit << "\n";
            // n_split只能小而不能大，因为sum_limit有最小值，则n_split有最大值m
            // 得出n_split <= m
            if (n_split <= m) {
                if (sum_limit < min_max_sum) {
                    min_max_sum = sum_limit;
                }
                // 可以尝试再缩小sum_limit
                rbound = sum_limit;
            } else {
                // sum_limit太小，得增大
                lbound = sum_limit + 1;
            }
        }
        // for (; sum_limit >= min_sum; sum_limit--) {
        //     // n_split会随着sum_limit减小而增大
        //     int n_split = least_split(nums, sum_limit);
        //     // cout << "#" << n_split << ", " << sum_limit << "\n";
        //     //
        //     n_split只能小而不能大，因为sum_limit有最小值，则n_split有最大值m
        //     // 得出n_split <= m
        //     if (n_split > m) {
        //         // cout << "#break, " << n_split << ", " << m << "\n";
        //         break;
        //     }
        // }
        return min_max_sum;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int m;

    nums = {7, 2, 5, 10, 8};
    m = 2;
    cout << s.splitArray(nums, m) << "\n";

    nums = {1, 2, 3, 4, 5};
    m = 2;
    cout << s.splitArray(nums, m) << "\n";

    nums = {1, 4, 4};
    m = 3;
    cout << s.splitArray(nums, m) << "\n";

    return 0;
}