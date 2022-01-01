/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-01 00:27
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
    int findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        // 先排除所有极端情况
        if (0 == n1) {
            return nums2[k - 1];
        }
        if (0 == n2) {
            return nums1[k - 1];
        }
        if (n1 + n2 == k) {
            return nums1[n1 - 1] > nums2[n2 - 1] ? nums1[n1 - 1]
                                                 : nums2[n2 - 1];
        }
        if (k <= n1 && nums1[k - 1] <= nums2[0]) {
            return nums1[k - 1];
        }
        if (k <= n2 && nums2[k - 1] <= nums1[0]) {
            return nums2[k - 1];
        }

        int l = 0, r = n1 - 1;
        while (l <= r) {
            // int i, j;  // 满足 i + 1 + j + 1 = k
            int i = (r - l) / 2 + l;
            int j = k - i - 2;
            if (j < 0) {
                r = i - 1;
                continue;
            }
            if (j >= n2) {
                l = i + 1;
                continue;
            }
            if (nums1[i] <= nums2[j]) {
                if (i == n1 - 1 || nums2[j] <= nums1[i + 1]) {
                    return nums2[j];
                }
                // i扩j缩
                l = i + 1;
            } else {
                if (j == n2 - 1 || nums1[i] <= nums2[j + 1]) {
                    return nums1[i];
                }
                // i缩j扩
                r = i - 1;
            }
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 假设加起来奇数
        int n1 = nums1.size(), n2 = nums2.size();
        if ((n1 + n2) % 2 == 1) {
            int mid = (n1 + n2 + 1) / 2;
            return findKthSortedArrays(nums1, nums2, mid);
        } else {
            int mid1 = (n1 + n2) / 2;
            int mid2 = mid1 + 1;
            return ((double)findKthSortedArrays(nums1, nums2, mid1) +
                    (double)findKthSortedArrays(nums1, nums2, mid2)) /
                   2;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;

    nums1 = {1, 3}, nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << '\n';

    nums1 = {1, 2}, nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << '\n';

    nums1 = {0, 0}, nums2 = {0, 0};
    cout << sol.findMedianSortedArrays(nums1, nums2) << '\n';

    nums1 = {}, nums2 = {1};
    cout << sol.findMedianSortedArrays(nums1, nums2) << '\n';

    nums1 = {2}, nums2 = {};
    cout << sol.findMedianSortedArrays(nums1, nums2) << '\n';

    return 0;
}