#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;  // 靠左
            int num = nums[mid];
            if (target == num) {
                return mid;
            } else if (target < num) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution s;
    cout << s.search(nums, target) << endl;

    nums = {-1, 0, 3, 5, 9, 12};
    target = 2;
    cout << s.search(nums, target) << endl;

    return 0;
}