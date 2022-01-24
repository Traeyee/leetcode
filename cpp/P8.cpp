/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-09 17:27
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
    int myAtoi(string s) {
        int n = s.size();
        bool is_positive = true;

        int l = -1, r = -1;
        int state = 0;
        for (int i = 0; i < n; i++) {
            if (0 == state) {
                if (' ' == s[i]) {
                } else if ('-' == s[i]) {
                    is_positive = false;
                    state = 1;
                } else if ('+' == s[i]) {
                    state = 1;
                } else if ('0' == s[i]) {
                    state = 1;
                } else if ('1' <= s[i] && s[i] <= '9') {
                    l = i;
                    r = i;
                    state = 2;
                } else {
                    return 0;
                }
            } else if (1 == state) {
                if ('0' == s[i]) {
                } else if ('1' <= s[i] && s[i] <= '9') {
                    l = i;
                    r = i;
                    state = 2;
                } else {
                    return 0;
                }
            } else {
                if ('0' <= s[i] && s[i] <= '9') {
                    if (-1 == l) {
                        l = i;
                    }
                    r = i;
                } else {
                    break;
                }
            }
        }

        int MY_MIN = 1 << 31;
        int MY_MAX = ~INT_MIN;
        if (!(0 <= l && l <= r && r < n)) {
            return 0;
        } else if (r - l + 1 > 10 || (r - l + 1 == 10 && s[l] > '2')) {
            if (!is_positive) {
                return MY_MIN;
            }
            return MY_MAX;
        }

        int danger_num = is_positive ? MY_MAX : MY_MIN;
        int res = 0, base = 1;
        for (int i = r; i >= l; i--) {
            int x = (s[i] - '0') * base;
            if (is_positive) {
                danger_num -= x;
                if (danger_num <= 0) {
                    return MY_MAX;
                }
            } else {
                danger_num += x;
                if (danger_num >= 0) {
                    return MY_MIN;
                }
            }
            res += x;
            if (i > l) {
                base *= 10;
            }
        }

        if (!is_positive) {
            return -res;
        }
        return res;
    }
    int myAtoi0(string s) {
        // 策略：先存起来再操作
        int sign = 1;
        vector<char> nums;

        int state = 0;
        for (const auto& c : s) {
            if (0 == state) {
                if (' ' == c) {
                    continue;
                } else if ('-' == c) {
                    sign = -1;
                    state = 1;
                } else if ('+' == c) {
                    sign = 1;
                    state = 1;
                } else if ('0' <= c && c <= '9') {
                    if ('0' == c) {
                        state = 1;
                    } else {
                        nums.emplace_back(c);
                        state = 2;
                    }
                } else {
                    return 0;
                }
            } else if (1 == state) {  // 丢弃所有的0
                if ('0' <= c && c <= '9') {
                    if ('0' < c) {
                        nums.emplace_back(c);
                        state = 2;
                    }
                } else {
                    break;
                }
            } else {
                if ('0' <= c && c <= '9') {
                    nums.emplace_back(c);
                } else {
                    break;
                }
            }
        }

        int n_dec = nums.size();
        int THE_MIN = 1 << 31;
        int THE_MAX = ~THE_MIN;
        if (0 == n_dec) {
            return 0;
        }
        if (n_dec > 10) {
            return sign > 0 ? THE_MAX : THE_MIN;
        }
        if (10 == n_dec) {
            int num = nums[0] - '0';
            if (num * num > 2 * 2) {
                return sign > 0 ? THE_MAX : THE_MIN;
            }
        }

        int val = 0;
        int b = 1;
        int danger_num = sign > 0 ? THE_MAX : THE_MIN;
        for (int i = n_dec - 1; i >= 0; i--) {
            int num = nums[i] - '0';
            if (10 == n_dec) {
                if (sign > 0) {
                    danger_num -= num * b;
                    if (danger_num <= 0) {
                        // 太大，溢出
                        // cout << "#here " << danger_num << "\n";
                        return THE_MAX;
                    }
                } else {
                    danger_num += num * b;
                    // cout << "#here " << danger_num << "\n";
                    if (danger_num >= 0) {
                        return THE_MIN;
                    }
                }
            }
            val += num * b;
            // 溢出处理：提前跳出
            if (0 == i) {
                break;
            }
            b *= 10;
        }

        return sign * val;
    }
};

int main() {
    Solution sol;
    string s;

    s = "42";
    cout << sol.myAtoi(s) << "\n";

    s = "   -42";
    cout << sol.myAtoi(s) << "\n";

    s = "4193 with words";
    cout << sol.myAtoi(s) << "\n";

    s = "words and 987";
    cout << sol.myAtoi(s) << "\n";

    s = "-91283472332";
    cout << sol.myAtoi(s) << "\n";

    s = "21474836460";
    cout << sol.myAtoi(s) << "\n";

    s = "2147483646";
    cout << sol.myAtoi(s) << "\n";

    s = "-2147483648";
    cout << sol.myAtoi(s) << "\n";

    s = "20000000000000000000";
    cout << sol.myAtoi(s) << "\n";

    s = "  0000000000012345678";
    cout << sol.myAtoi(s) << "\n";

    return 0;
}