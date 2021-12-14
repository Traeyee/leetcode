/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-13 15:49
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
    // @param k: 1 <= k <= n
    int bulbSwitch(int n, int k) {
        if (n <= 1) {
            return n;
        }
        int state = 1;
        for (int i = 2; i <= n; i++) {
            if (k % i == 0) {
                state ^= 1;
            }
        }
        return state;
    }
    int bulbSwitch0(int n) {
        int cnt = 0;
        for (int k = 1; k <= n; k++) {
            cnt += bulbSwitch(n, k);
        }
        return cnt;
    }

    int bulbSwitch(int n) {
        double x1 = sqrt(n + 1) - 1;
        return ceil(x1);
    }
};

int main() {
    Solution sol;

    for (int n = 0; n <= 100; n++) {
        cout << n << ": " << sol.bulbSwitch(n) << "\n";
    }

    // 发现：
    // n1 < x(x+2) <= n2 ==> sqrt(n1 + 1) < x + 1 <= sqrt(n2 + 1)，而n1 = (x-1)(x+1)
    // n1 < n <= n2

    return 0;
}