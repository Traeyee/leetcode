/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-12 17:44
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
    // 定义：对于role，当剩下n个石子时，是否有必胜策略
    // role: 0轮到我下，1轮到对面下
    bool canWinNim(int n, int role, unordered_map<string, bool>& memo) {
        if (n < 1) {
            return false;  // 对面已经takes all了
        } else if (n <= 3) {
            return true;
        }

        stringstream ss;
        ss << n << '-' << role;
        auto key = ss.str();
        if (memo.end() != memo.find(key)) {
            return memo[key];
        }

        int oppos = role ^ 1;
        bool res = !canWinNim(n - 1, oppos, memo) ||
                   !canWinNim(n - 2, oppos, memo) ||
                   !canWinNim(n - 3, oppos, memo);

        memo[key] = res;
        return res;
    }

    bool canWinNim0(int n) {
        unordered_map<string, bool> memo;
        return canWinNim(n, 0, memo);
    }

    bool canWinNim(int n) {
        return n % 4;
    }
};

int main() {
    Solution sol;
    int n;

    n = 4;
    cout << sol.canWinNim(n) << "\n";

    n = 1;
    cout << sol.canWinNim(n) << "\n";

    n = 2;
    cout << sol.canWinNim(n) << "\n";

    n = 1348820612;
    cout << sol.canWinNim(n) << "\n";

    return 0;
}