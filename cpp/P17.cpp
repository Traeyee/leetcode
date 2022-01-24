/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-17 09:27
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
    vector<string> letterCombinations(string digits) {
        if (0 == digits.size()) {
            return {};
        }
        
        map<char, vector<char>> num_map = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
        };

        vector<string> res = {""}, tmp_res;
        for (char num : digits) {
            tmp_res.clear();
            for (char c : num_map[num]) {
                for (auto s : res) {
                    string s2 = s;
                    s2.push_back(c);
                    tmp_res.emplace_back(s2);
                }
            }
            res = tmp_res;
        }

        return res;
    }
};

template <class T>
void print_vector(vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << ", ";
    }
    cout << '\n';
}

int main() {
    Solution sol;
    string digits;
    vector<string> res;

    digits = "23";
    res = sol.letterCombinations(digits);
    print_vector(res);

    digits = "";
    res = sol.letterCombinations(digits);
    print_vector(res);

    digits = "2";
    res = sol.letterCombinations(digits);
    print_vector(res);

    return 0;
}