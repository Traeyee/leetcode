/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-12 16:25
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
    // 基于题26的简洁解法：https://zhuanlan.zhihu.com/p/41373837
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};