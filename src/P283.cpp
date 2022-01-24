/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-12 17:35
 * @brief  实际就是P27
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
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (0 != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        for (int i1 = i + 1; i1 < nums.size(); i1++) {
            nums[i1] = 0;
        }
    }
};