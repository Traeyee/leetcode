/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-26 22:48
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
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int tmp;
        int pos = k % n, last_num = nums[0];
        for (int i = 0; i < n; i++) {
            tmp = nums[pos];
            nums[pos] = last_num;
            last_num = tmp;
            pos = (pos + k) % n;
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
    int k;

    nums = {1, 2, 3, 4, 5, 6, 7}, k = 3;
    sol.rotate(nums, k);
    print_vector(nums);

    nums = {-1, -100, 3, 99}, k = 2;
    sol.rotate(nums, k);
    print_vector(nums);

    return 0;
}