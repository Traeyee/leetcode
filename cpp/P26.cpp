/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-10 23:31
 * @brief  双指针法会简洁很多，只要是数组，怎么也得想想双指针
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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), total_rm = 0;
        int i = 0;
        int last_num = -1000, last_idx = -1;

        while (i < n - total_rm) {
            // cout << "# " << total_rm << "--" << i << ": " << nums[i] << "\n";
            if (nums[i] == last_num) {
                i++;
            } else {
                if (last_idx + 1 < i) {
                    // 得移过来
                    int n_rm = i - last_idx - 1;
                    // cout << "# here: " << n_rm << " * " << last_num << "\n";
                    total_rm += n_rm;
                    for (int j = last_idx + 1; j < n - total_rm; j++) {
                        nums[j] = nums[j + n_rm];
                    }

                    // cout << "# ";
                    // for (int i2 = 0; i2 < n - total_rm; i2++) {
                    //     cout << "[" << i2 << "]" << nums[i2] << ", ";
                    // }
                    // cout << "\n";

                }
                last_idx++;
                last_num = nums[last_idx];
                i = last_idx + 1;
            }
        }

        return last_idx + 1;
    }
};

void run_example(Solution sol, vector<int>& nums) {
    int k = sol.removeDuplicates(nums);
    for (int i = 0; i < k; i++) {
        cout << nums[i] << ", ";
    }
    cout << "\n";
}

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 1, 2};
    run_example(sol, nums);

    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    run_example(sol, nums);

    return 0;
}