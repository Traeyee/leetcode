/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-16 14:35
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
    // 牛顿切线法
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }

        int x_n = x / 2;
        while (1) {
            int x_n1 = (x_n + x / x_n) / 2;
            if (x_n1 == x_n) {
                return x_n;
            } else if (x_n + 1 == x_n1) {
                return x_n;
            }
            cout << x_n << ", " << x_n1 << "\n";

            x_n = x_n1;
        }
        return -1;
    }
    // 长方形变正方形的思路
    int mySqrt0(int x) {
        int l = x / 2, w = 2;
        while (1) {
            l = (l + w) / 2;
            w = x / l;
            if (l == w) {
                return l;
            } else if (l + 1 == w) {
                return l;
            } else if (l == w + 1) {
                return w;
            }
        }
        return -1;
    }

    // 这个思路是最CS朴素的，但可能会超int范围，没办法实用
    int mySqrt__PART(int x) {
        // TODO: x范围
        int l = 0, r = x;
        int x1;
        while (l <= r) {
            x1 = (l + r) / 2;
            if (x1 * x1 == x) {
                return x1;
            } else if (x1 * x1 < x) {
                if ((x1 + 1) * (x1 + 1) > x) {
                    return x1;
                }
                // 小了
                l = x1 + 1;
            } else {
                // 大了
                r = x1 - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    cout << sol.mySqrt(0) << "\n";
    cout << sol.mySqrt(1) << "\n";
    cout << sol.mySqrt(2) << "\n";
    cout << sol.mySqrt(3) << "\n";

    cout << sol.mySqrt(4) << "\n";

    cout << sol.mySqrt(8) << "\n";

    cout << sol.mySqrt(100) << "\n";

    return 0;
}