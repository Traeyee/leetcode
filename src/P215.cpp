/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-14 11:39
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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>
            heap;  // 默认最大堆，greater变最小堆

        for (int ele : nums) {
            if (heap.size() < k) {
                heap.push(ele);
            } else {
                int kth_large = heap.top();
                if (ele > kth_large) {
                    heap.pop();
                    heap.push(ele);
                }
            }
        }

        return heap.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    cout << sol.findKthLargest(nums, k) << "\n";

    return 0;
}