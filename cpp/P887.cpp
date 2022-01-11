/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-12 23:05
 * @brief  思路是对了，但代码没写对，下次来写再试
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
   // dp(k, n): 
   int dp(int k, int n, map<int, map<int, int>>& memo) {
        if (memo.count(k) && memo[k].count(n)) {
            return memo[k][n];
        }

        if (1 == k || n <= 2) {
            return n;
        }

        int mid = (n + 1) / 2;
        int below = dp(k - 1, mid - 1, memo);
        int upon = dp(k - 1, n - mid, memo);
        int res = below > upon ? below : upon;
        if (!memo.count(k)) {
            memo[k] = map<int, int>();
        }
        memo[k][n] = res;
        return res;
    }
    int superEggDrop(int k, int n) {
        map<int, map<int, int>> memo;
        return dp(k, n, memo);
    }
};

int main() {
    Solution sol;
    int k, n;

    k = 1, n = 2;
    cout << sol.superEggDrop(k, n) << '\n';

    k = 2, n = 6;
    cout << sol.superEggDrop(k, n) << '\n';

    k = 3, n = 14;
    cout << sol.superEggDrop(k, n) << '\n';

    k = 1, n = 3;
    cout << sol.superEggDrop(k, n) << '\n';

    k = 2, n = 9;
    cout << sol.superEggDrop(k, n) << '\n';

    return 0;
}