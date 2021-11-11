#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> hashmap;
        for (size_t i = 0; i < nums.size(); i++) {
            hashmap[target - nums[i]] = i;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (hashmap.end() != hashmap.find(nums[i])) {
                if (i != hashmap[nums[i]]) {
                    ret.emplace_back(i);
                    ret.emplace_back(hashmap[nums[i]]);
                    break;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    auto ret = s.twoSum(nums, 9);
    for (const auto& ele : ret) {
        cout << ele << ",";
    }
    return 0;
}