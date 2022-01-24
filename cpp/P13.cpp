/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-09 21:17
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
    int romanToInt(string s) {
        int n = s.size();
        int i = 0;
        int y = 0;
        unordered_map<char, int> roman_map = {
            {'V', 5}, {'L', 50}, {'D', 500}, {'M', 1000}};
        while (i < n) {
            if ('I' == s[i]) {
                if (i + 1 < n) {
                    if ('V' == s[i + 1]) {
                        y += 4;
                        i += 2;
                        continue;
                    } else if ('X' == s[i + 1]) {
                        y += 9;
                        i += 2;
                        continue;
                    }
                }
                y += 1;
            } else if ('X' == s[i]) {
                if (i + 1 < n) {
                    if ('L' == s[i + 1]) {
                        y += 40;
                        i += 2;
                        continue;
                    } else if ('C' == s[i + 1]) {
                        y += 90;
                        i += 2;
                        continue;
                    }
                }
                y += 10;
            } else if ('C' == s[i]) {
                if (i + 1 < n) {
                    if ('D' == s[i + 1]) {
                        y += 400;
                        i += 2;
                        continue;
                    } else if ('M' == s[i + 1]) {
                        y += 900;
                        i += 2;
                        continue;
                    }
                }
                y += 100;
            } else {
                y += roman_map[s[i]];
            }

            i++;
        }

        return y;
    }
};

int main() {
    Solution sol;
    string s;

    s = "III";
    cout << sol.romanToInt(s) << "\n";

    s = "IV";
    cout << sol.romanToInt(s) << "\n";

    s = "IX";
    cout << sol.romanToInt(s) << "\n";

    s = "LVIII";
    cout << sol.romanToInt(s) << "\n";

    s = "MCMXCIV";
    cout << sol.romanToInt(s) << "\n";

    return 0;
}