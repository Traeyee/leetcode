/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-11 16:42
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
   // 可解，但太慢了，TL，更先进解法应该是基于这个的关系式
    int preimageSizeFZF(int k) {
        unordered_map<int, int> cnt_map;
        int cnt = 0;
        int i = 5;
        while (cnt <= k) {
            if (cnt == k) {
                return 5;
            }
            // 计算i的阶乘有多少个tailing-0

            // 单是i能提供多少个0
            int cnt1 = cnt_map[i / 5] + 1;
            cnt_map[i] = cnt1;

            cnt += cnt1;
            // cout << "# " << i << ": " << cnt << "\n";
            if (i >= 1000) {
                break;
            }
            i += 5;
        }

        return 0;
    }
};

int main() {
    Solution sol;
    int k;

    k = 10;
    cout << sol.preimageSizeFZF(k) << "\n";

    k = 5;
    cout << sol.preimageSizeFZF(k) << "\n";

    k = 3;
    cout << sol.preimageSizeFZF(k) << "\n";

    k = 80502705;
    cout << sol.preimageSizeFZF(k) << "\n";

    return 0;
}