/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-27 10:11
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
    int titleToNumber(string columnTitle) {
        int res = 0;

        for (const char& c : columnTitle) {
            int d = c - 'A' + 1;
            res = res * 26 + d;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string columnTitle;

    columnTitle = "A";
    cout << sol.titleToNumber(columnTitle) << "\n";

    columnTitle = "AB";
    cout << sol.titleToNumber(columnTitle) << "\n";

    columnTitle = "ZY";
    cout << sol.titleToNumber(columnTitle) << "\n";

    columnTitle = "FXSHRXW";
    cout << sol.titleToNumber(columnTitle) << "\n";

    return 0;
}