/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-24 23:24
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
    double myPow(double x, int n) {
        if (0 == n) {
            return 1.0;
        }
        if (1 == n) {
            return x;
        }
        int lower_bound = 1 << 31;
        if (n == lower_bound) {
            return myPow(x, n + 1) / x;
        }
        if (n < 0) {
            return 1 / myPow(x, -n);
        }

        if (n % 2 == 0) {
            double sub_res = myPow(x, n / 2);
            return sub_res * sub_res;
        } else {
            double sub_res = myPow(x, (n - 1) / 2);
            return x * sub_res * sub_res;
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    double x;
    int n;

    x = 2.00000, n = 10;
    cout << sol.myPow(x, n) << '\n';

    x = 2.10000, n = 3;
    cout << sol.myPow(x, n) << '\n';

    x = 2.00000, n = -2;
    cout << sol.myPow(x, n) << '\n';

    return 0;
}