/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-16 23:13
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
        int l = left_bound, r = n - 1;

        vector<vector<int>> res;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                vector<int> tmp = {-target, nums[l], nums[r]};
                // cout << "## " << left_bound << ", " << l << ", " << r <<
                // '\n';
                res.emplace_back(tmp);
                l++;
                r--;
            }
        }

        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 教训：永远要以int作为条件
        int n = nums.size();
        sort(nums.begin(), nums.end(), less<int>());

        vector<vector<int>> all_res;
        set<string> dup_set;
        stringstream ss;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            auto res = twoSum(nums, i + 1, -nums[i]);
            for (const auto& sub_res : res) {
                ss.str(string());
                ss << sub_res[0] << ',' << sub_res[1] << ',' << sub_res[2];
                if (dup_set.end() == dup_set.find(ss.str())) {
                    // cout << ss.str() << '\n';
                    all_res.emplace_back(sub_res);
                }
                dup_set.insert(ss.str());
            }
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