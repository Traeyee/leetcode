/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-10-30 15:59
 * @brief
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
    vector<int> quick_sort(vector<int>& nums) {
        stack<pair<int, int>> stk;
        stk.push(make_pair(0, nums.size()));
        while (stk.size() > 0) {
            int l = stk.top().first, r = stk.top().second;
            // cout << "#" << l << ", " << r << "\n";
            stk.pop();
            if (l >= r - 1) {
                continue;
            }

            int guard = nums[l];
            int first_right_pos = l + 1;
            int tmp;
            // 记住，划分过程不可能动到guard
            for (int next_check_pos = l + 1; next_check_pos < r;
                 next_check_pos++) {
                if (nums[next_check_pos] < guard) {
                    // 交换
                    tmp = nums[first_right_pos];
                    nums[first_right_pos] = nums[next_check_pos];
                    nums[next_check_pos] = tmp;
                    first_right_pos++;
                }
            }
            int last_left_pos = first_right_pos - 1;
            tmp = nums[last_left_pos];
            nums[last_left_pos] = guard;
            nums[l] = tmp;
            int cur_guard_pos = last_left_pos;
            stk.push(make_pair(l, cur_guard_pos));
            stk.push(make_pair(first_right_pos, r));

            // cout << "##";
            // for (size_t i = l; i < r; i++) {
            //     cout << nums[i] << ", ";
            // }
            // cout << "\n";
        }

        return nums;
    }
    vector<int> bubble_sort(vector<int>& nums) {
        int tmp;
        for (int rbound = nums.size(); rbound > 0; rbound--) {
            for (size_t i = 0; i + 1 < rbound; i++) {
                if (nums[i] > nums[i + 1]) {
                    tmp = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = tmp;
                }
            }
        }
        return nums;
    }
    vector<int> sortArray(vector<int>& nums) { return bubble_sort(nums); }
};

int main() {
    vector<int> nums = {5, 2, 3, 1};
    Solution s;
    for (const auto& ele : s.sortArray(nums)) {
        cout << ele << ", ";
    }
    cout << "\n";

    nums = {5, 1, 1, 2, 0, 0};
    for (const auto& ele : s.sortArray(nums)) {
        cout << ele << ", ";
    }
    cout << "\n";
    return 0;
}