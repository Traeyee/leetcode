/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-10-30 19:32
 * @brief  Time Limit Exceeded，得用二分法优化一下
 */
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

class Solution {
   public:
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
    int splitArray(vector<int>& nums, int m) {
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
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;
    Solution s;
    cout << s.splitArray(nums, m) << "\n";

    nums = {1, 2, 3, 4, 5};
    m = 2;
    cout << s.splitArray(nums, m) << "\n";

    nums = {1, 4, 4};
    m = 3;
    cout << s.splitArray(nums, m) << "\n";

    unordered_map<string, int> tmp;
    cout << "#" << tmp.bucket_count() << "\n";

    return 0;
}