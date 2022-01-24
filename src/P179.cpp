/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-09 15:13
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
    string my_itoa(int x) {
        int x1 = x;
        stack<char> stk;
        while (x1) {
            int r = x1 % 10;
            stk.push(r + '0');
            x1 /= 10;
        }
        string res;
        while (stk.size()) {
            res.push_back(stk.top());
            stk.pop();
        }
        if (0 == res.size()) {
            return "0";
        }
        return res;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> s_nums;
        bool all_zeroes = true;
        for (int x : nums) {
            if (0 != x) {
                all_zeroes = false;
            }
            s_nums.emplace_back(my_itoa(x));
        }
        if (all_zeroes) {
            return "0";
        }

        auto cmp = [](string& s1, string& s2) {
            string p1 = s1 + s2, p2 = s2 + s1;
            for (int i = 0; i < p1.size(); i++) {
                if (p1[i] > p2[i]) {
                    return true;
                } else if (p1[i] < p2[i]) {
                    return false;
                }
            }
            return false;
        };
        sort(s_nums.begin(), s_nums.end(), cmp);

        string res;
        for (const auto& s : s_nums) {
            res += s;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {10, 2};
    cout << sol.largestNumber(nums) << '\n';

    nums = {3, 30, 34, 5, 9};
    cout << sol.largestNumber(nums) << '\n';

    nums = {1};
    cout << sol.largestNumber(nums) << '\n';

    nums = {10};
    cout << sol.largestNumber(nums) << '\n';

    nums = {0, 0};
    cout << sol.largestNumber(nums) << '\n';

    return 0;
}