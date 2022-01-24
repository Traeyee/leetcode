/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-08 15:07
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
    

    // 太复杂了，还有更简洁的
    double findMedianSortedArrays0(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k = (m + n) / 2;  // 中位数下标
        // 先假设m + n = 2k + 1
        // mid在nums1中为第p1个，在nums2为第p2个，则p1 + p2 = k = (m + n) / 2
        // 从nums1选p1，那么mid应该比nums2的第2k - p1大，比第k - p1 + 1小
        // 如果太大，应该变小，如果太小，应该变大
        // 假设下标从1开始，p1 + p2 = k + 1
        // 若nums2[p2] < nums1[p1] < nums2[p2 + 1]，则就是p1
        // 若nums1[p1] < nums2[p2] < nums1[p1 + 1]，则就是p2
        // 若nums1[p1 + 1] < nums2[p2]，p1要变大了
        
        // 处理特殊情况
        if (nums1[0] > nums2[n - 1]) {
            if (m < n) {
                return nums2[k];
            } else {
                return nums1[k - n];
            }
        }
        if (nums2[0] > nums1[m - 1]) {
            if (m < n) {
                return nums2[k - m];
            } else {
                return nums1[k];
            }
        }

        int l1 = 0, r1 = m;
        while (1) {
            int p1 = (l1 + r1) / 2;
            int p2 = k + 1 - p1;


        }





    }
};