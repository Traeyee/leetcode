/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-16 19:15
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
    void sortColors(vector<int>& nums) {
        int n_0 = 0, n_1 = 0, n_2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int clr = nums[i];
            int start_1 = n_0, start_2 = n_0 + n_1;
            if (0 == clr) {
                if (n_1 > 0 && n_2 > 0) {
                    swap(nums[i], nums[start_2]);
                    swap(nums[start_2], nums[start_1]);
                } else if (n_1 > 0 && n_2 == 0) {
                    swap(nums[i], nums[start_1]);
                } else if (n_1 == 0 && n_2 > 0) {
                    swap(nums[i], nums[start_2]);
                }
                n_0++;
            } else if (1 == clr) {
                if (n_2 > 0) {
                    swap(nums[i], nums[start_2]);
                }
                n_1++;
            } else {
                n_2++;
            }
        }
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

    nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    print_vector(nums);

    nums = {2, 0, 1};
    sol.sortColors(nums);
    print_vector(nums);
    
    nums = {0};
    sol.sortColors(nums);
    print_vector(nums);

    nums = {1};
    sol.sortColors(nums);
    print_vector(nums);

    return 0;
}