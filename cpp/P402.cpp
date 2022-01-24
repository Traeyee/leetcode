/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-03 18:33
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
    bool lt(string s1, int idx1, string s2, int idx2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (i == idx1) {
                i++;
                continue;
            }
            if (j == idx2) {
                j++;
                continue;
            }
            if (s1[i] < s2[j]) {
                return true;
            } else if (s1[i] > s2[j]) {
                return false;
            }
            i++;
            j++;
        }
        return false;
    }

    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k) {
            return "0";
        }
        if (0 == k) {
            string num2;
            int state = 0;
            for (int i = 0; i < n; i++) {
                if ('0' == num[i] && 0 == state) {
                    continue;
                }
                state = 1;
                num2.push_back(num[i]);
            }
            if (0 == num2.size()) {
                return "0";
            }
            return num2;
        }

        int min_i = 0;
        for (int i = 1; i < n; i++) {
            if (lt(num, i, num, min_i)) {
                min_i = i;
            }
        }
        string num2;
        for (int i = 0; i < n; i++) {
            if (i == min_i) {
                continue;
            }
            num2.push_back(num[i]);
        }
        return removeKdigits(num2, k - 1);
    }
};

int main() {
    Solution sol;
    string num;
    int k;

    num = "1432219", k = 3;
    cout << sol.removeKdigits(num, k) << '\n';

    num = "10200", k = 1;
    cout << sol.removeKdigits(num, k) << '\n';

    num = "10", k = 2;
    cout << sol.removeKdigits(num, k) << '\n';

    return 0;
}