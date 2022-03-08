/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-03-06 22:58
 * @brief  
 */
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
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
    string largestNumber(vector<int>& nums) {
        vector<string> s_nums;
        for (auto x : nums) {
            s_nums.emplace_back(to_string(x));
        }
        auto cmp = [](string s1, string s2) {
            string sa = s1 + s2, sb = s2 + s1;
            for (int i = 0; i < sa.size(); i++) {
                if (sa[i] > sb[i]) {
                    return true;
                } else if (sa[i] < sb[i]) {
                    return false;
                }
            }
            return false;
        };
        // sort
        sort(s_nums.begin(), s_nums.end(), cmp);

        string res;
        for (const auto& s : s_nums) {
            if ("0" == res && "0" == s) {
                continue;
            }
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