/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-24 11:53
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
    vector<int> diffWaysToCompute(vector<int>& nums, vector<char>& ops, int l,
                                  int r) {
        if (l == r) {
            return {nums[l]};
        }
        vector<int> res;

        int l_end = l;
        while (l_end < r) {
            auto res1 = diffWaysToCompute(nums, ops, l, l_end);
            auto res2 = diffWaysToCompute(nums, ops, l_end + 1, r);
            for (int operand1 : res1) {
                for (int operand2 : res2) {
                    if ('+' == ops[l_end]) {
                        res.emplace_back(operand1 + operand2);
                    } else if ('-' == ops[l_end]) {
                        res.emplace_back(operand1 - operand2);
                    } else if ('*' == ops[l_end]) {
                        res.emplace_back(operand1 * operand2);
                    }
                }
            }
            l_end++;
        }

        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;

        string s1 = "";
        for (char c : expression) {
            if ('0' <= c && c <= '9') {
                s1.push_back(c);
            } else {
                nums.emplace_back(atoi(s1.c_str()));
                s1 = "";
                ops.emplace_back(c);
            }
        }
        nums.emplace_back(atoi(s1.c_str()));

        return diffWaysToCompute(nums, ops, 0, nums.size() - 1);
    }
};

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << "\n";
}

int main() {
    Solution sol;
    string expression;
    vector<int> res;

    expression = "2-1-1";
    res = sol.diffWaysToCompute(expression);
    print_vector(res);

    expression = "2*3-4*5";
    res = sol.diffWaysToCompute(expression);
    print_vector(res);

    return 0;
}