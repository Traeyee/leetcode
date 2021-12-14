/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-11 16:07
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
    // 发现规律
    int trailingZeroes(int n) {
        int cnt = 0;
        int base = 5;
        while (n >= base) {
            cnt += n / base;
            base *= 5;
        }

        return cnt;
    }
    // 复习
    int trailingZeroes1(int n) {
        unordered_map<int, int> five_cnt_map;
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (0 == i % 5) {
                int cnt1 = 1 + five_cnt_map[i / 5];
                five_cnt_map[i] = cnt1;
                cnt += cnt1;
            }
        }

        return cnt;
    }

    int trailingZeroes0(int n) {
        unordered_map<int, int> five_cnt_map;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (0 == i % 5) {
                int cnt1 = five_cnt_map[i / 5] + 1;
                five_cnt_map[i] = cnt1;
                cnt += cnt1;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    int n;

    n = 3;
    cout << sol.trailingZeroes(n) << "\n";

    n = 5;
    cout << sol.trailingZeroes(n) << "\n";

    n = 0;
    cout << sol.trailingZeroes(n) << "\n";

    n = 50;
    cout << sol.trailingZeroes(n) << "\n";

    return 0;
}