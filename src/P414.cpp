/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-03 21:35
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
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if (1 == n) {
            return nums[0];
        } else if (2 == n) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        
        vector<int> max_arr = {nums[0], nums[1], nums[2]};
        sort(max_arr.begin(), max_arr.end(), greater<int>());
        for (int i = 3; i < n; i++) {
            if (nums[i] > max_arr[0]) {
                max_arr[2] = max_arr[1];
                max_arr[1] = max_arr[0];
                max_arr[0] = nums[i];
            } else if (max_arr[0] > nums[i] && nums[i] > max_arr[1]) {
                max_arr[2] = max_arr[1];
                max_arr[1] = nums[i];
            } else if (max_arr[1] > nums[i] && nums[i] > max_arr[2]) {
                max_arr[2] = nums[i];
            }
        }
        return max_arr[2];
    }
};