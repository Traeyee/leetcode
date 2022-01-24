/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-12 10:52
 * @brief
 * 最暴力的思路当然是利用一个counter或bool数组了
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
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> cands;
        for (int i : nums) {
            // cout << "##:" << i << "\n";
            // cout << "#0: " << nums[i - 1] << "\n";
            if (i > 0) {
                nums[i - 1] *= -1;
            } else {
                nums[-i - 1] *= -1;
            }
            // cout << "#1: " << nums[i - 1] << "\n";
        }
        for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i] << "\n";
            if (nums[i] > 0) {
                // cout << "# " << i + 1 << "\n";
                cands.emplace_back(i + 1);
            }
        }
        for (const auto& i : nums) {
            // cout << i << "\n";
            if (cands[0] == i || cands[0] == -i) {
                return cands;
            }
        }
        return {cands[1], cands[0]};
    }
};

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << "\n";
}

int main() {
    Solution sol;
    vector<int> nums;

    vector<int> res;

    // nums = {1, 2, 2, 4};
    // res = sol.findErrorNums(nums);
    // print_vector(res);

    // nums = {1, 1};
    // res = sol.findErrorNums(nums);
    // print_vector(res);

    // nums = {2, 2};
    // res = sol.findErrorNums(nums);
    // print_vector(res);

    nums = {1, 5, 3, 2, 2, 7, 6, 4, 8, 9};
    res = sol.findErrorNums(nums);
    print_vector(res);

    return 0;
}