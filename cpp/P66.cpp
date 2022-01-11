/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-03 00:50
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
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n - 1]++;
        vector<int> res;
        bool leftmost_carry = false;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] >= 10) {
                digits[i] -= 10;
                if (i - 1 >= 0) {
                    digits[i - 1]++;
                } else {
                    leftmost_carry = true;
                }
            }
        }
        if (leftmost_carry) {
            res.emplace_back(1);
        }
        res.insert(res.end(), digits.begin(), digits.end());

        return res;
    }
};