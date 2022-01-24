#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// nums 中可能有多对儿元素之和都等于 target，请你的算法返回所有和为 target 的元素对儿，其中不能出现重复。
class Solution {
   public:
    vector<vector<int>> twoSumTarget(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        unordered_map<int, int> hashmap;
        unordered_set<string> key_hashes;
        for (size_t i = 0; i < nums.size(); i++) {
            hashmap[target - nums[i]] = i;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (hashmap.end() != hashmap.find(nums[i])) {
                if (i != hashmap[nums[i]]) {
                    ret.emplace_back(i);
                    ret.emplace_back(hashmap[nums[i]]);
                }
            }
        }
        return ret;
    }

    vector<vector<int>> nSum(int n, vector<int>& nums, int target) {
        if (2 == n) {
            return twoSum()
        }

        vector<vector<int>> ret;
        unordered_set<string> hashset;
        for (int i = 0; i < n; i++) {
            auto rst = nSum(n - 1, nums, target - nums[i]);
            for (auto& indices : rst) {
                if (indices.end() != find(indices.begin(), indices.end(), i)) {
                    indices.emplace_back(i);
                    sort(indices.begin(), indices.end());
                    stringstream ss;
                    for (const auto& ele : indices) {
                        ss << ele;
                    }
                    string key = ss.str();
                    if (hashset.end() != hashset.find(key)) {
                        ret.emplace_back(indices);
                    }
                }
            }
        }
        return ret;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return nSum(4, nums, target);
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution s;
    auto ret = s.fourSum(nums, 0);
    for (const auto& indices : ret) {
        for (const auto& ele : indices) {
        cout << ele << ",";
        }
        cout << "\n";
    }
}