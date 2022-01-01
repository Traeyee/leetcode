/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-25 10:22
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
    void wiggleSort(vector<int>& nums) {
        
    }
    void wiggleSort__NAIVE(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        sort(nums.begin(), nums.end());

        int j = n - 1;
        int i = (n - 1) / 2;
        vector<int> res;
        // 教训：无符号数与负数不要比较
        while (res.size() + 2 <= n) {
            res.emplace_back(nums[i]);
            res.emplace_back(nums[j]);
            i--;
            j--;
        }
        if (n % 2 == 1) {
            res.emplace_back(nums[0]);
        }
        swap(nums, res);
    }
};

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 5, 1, 1, 6, 4};
    sol.wiggleSort(nums);
    print_vector(nums);

    nums = {1, 3, 2, 2, 3, 1};
    sol.wiggleSort(nums);
    print_vector(nums);

    nums = {4, 5, 5, 6};
    sol.wiggleSort(nums);
    print_vector(nums);

    nums = {1};
    sol.wiggleSort(nums);
    print_vector(nums);

    return 0;
}