/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-20 13:13
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
    vector<vector<int>> twoSum(vector<int>& nums, int left_bound, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        int l = left_bound, r = n - 1;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                l++;
            } else if (nums[l] + nums[r] > target) {
                r--;
            } else {
                vector<int> sub_res = {-target, nums[l], nums[r]};
                // cout << "## " << sub_res[0] << ", " << sub_res[1] << ", " << sub_res[2] << '\n';
                res.emplace_back(sub_res);
                int l1 = l + 1;
                while (l1 < r && nums[l1] == nums[l]) {
                    l1++;
                }
                l = l1;
                int r1 = r - 1;
                while (l < r1 && nums[r1] == nums[r]) {
                    r1--;
                }
                r = r1;
            }
        }

        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int n = nums.size();

        vector<vector<int>> all_res;
        int i = 0;
        while (i < n) {
            auto res = twoSum(nums, i + 1, -nums[i]);
            all_res.insert(all_res.end(), res.begin(), res.end());
            
            int i1 = i + 1;
            while (i1 < n && nums[i1] == nums[i]) {
                i1++;
            }
            i = i1;
        }

        return all_res;
    }
};

template <class T>
void print_vector_vector(vector<vector<T>>& nums_vector) {
    for (const auto& nums : nums_vector) {
        cout << '[';
        for (const auto& num : nums) {
            cout << num << ", ";
        }
        cout << "], ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    vector<int> nums;
    vector<vector<int>> res;

    nums = {-1, 0, 1, 2, -1, -4};
    res = sol.threeSum(nums);
    print_vector_vector(res);

    nums = {};
    res = sol.threeSum(nums);
    print_vector_vector(res);

    nums = {0};
    res = sol.threeSum(nums);
    print_vector_vector(res);

    return 0;
}