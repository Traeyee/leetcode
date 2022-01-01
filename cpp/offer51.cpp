/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-19 20:23
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
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
    int _merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int rev_cnt = 0;
        int mid = (r - l) / 2 + l;
        rev_cnt += _merge_sort(nums, l, mid);
        rev_cnt += _merge_sort(nums, mid + 1, r);

        vector<int> tmp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp.emplace_back(nums[i]);
                i++;
            } else {
                tmp.emplace_back(nums[j]);
                j++;

                rev_cnt += mid - i + 1;
            }
        }
        while (i <= mid) {
            tmp.emplace_back(nums[i]);
            i++;
        }
        while (j <= r) {
            tmp.emplace_back(nums[j]);
            j++;
        }

        for (i = 0; i < tmp.size(); i++) {
            nums[l + i] = tmp[i];
        }
        return rev_cnt;
    }

    int reversePairs(vector<int>& nums) {
        return _merge_sort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {7, 5, 6, 4};
    cout << sol.reversePairs(nums) << '\n';

    return 0;
}