/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-28 18:58
 * @brief
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
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int k1 = k % n;
        if (0 == k1) {
            return;
        }
        vector<int> tmp_vec;
        for (int i = n - k1; i < n; i++) {
            tmp_vec.emplace_back(nums[i]);
        }

        for (int i = n; i >= k1; i--) {
            nums[i] = nums[i - k1];
        }
        for (int i = 0; i < k1; i++) {
            nums[i] = tmp_vec[i];
        }
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
    int k;

    nums = {1, 2, 3, 4, 5, 6, 7}, k = 3;
    sol.rotate(nums, k);
    print_vector(nums);

    nums = {-1, -100, 3, 99}, k = 2;
    sol.rotate(nums, k);
    print_vector(nums);

    return 0;
}