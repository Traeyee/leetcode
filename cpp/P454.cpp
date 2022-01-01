/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-31 23:54
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        map<int, int> counter;
        for (int x1 : nums1) {
            for (int x2 : nums2) {
                counter[-x1 - x2]++;
            }
        }
        int res = 0;
        for (int x3 : nums3) {
            for (int x4 : nums4) {
                res += counter[x3 + x4];
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2, nums3, nums4;

    nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << '\n';

    nums1 = {0}, nums2 = {0}, nums3 = {0}, nums4 = {0};
    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << '\n';

    return 0;
}