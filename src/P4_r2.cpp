/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-11 14:25
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
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
        // TODO: 各种特殊情况
        if (nums1[n1 - 1] <= nums2[0]) {
            if (k <= n1) {
                return nums1[k - 1];
            } else {
                return nums2[k - n1 - 1];
            }
        }
        // 因为 (i + 1) + (j + 1) = k，所以确定i必能确定j，我们以i为移动点
        // 假设存在i使得上式成立
        int l, r;

        while (1) {
            int i = (r - l) / 2 + l;
            int j = k - i - 2;
            // TODO: 各种越界
            if (nums1[i] <= nums2[j]) {
                if (nums2[j] <= nums1[i + 1]) {
                    return nums2[j];
                } else {
                    l = i + 1;
                    continue;
                }
            } else {
                if (nums1[i] <= nums2[j + 1]) {
                    return nums1[i];
                }
                if (nums1[i] > nums2[j + 1]) {
                    r = i - 1;
                    continue;
                }
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {}
};