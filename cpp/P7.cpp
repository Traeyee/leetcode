/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-09 11:49
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
    int reverse(int x) {
        if (0 == x) {
            return 0;
        }

        vector<int> nums;
        int x1 = x;
        while (x1) {
            int num = x1 % 10;
            nums.emplace_back(num);
            x1 /= 10;
        }

        int n_dec = nums.size();
        if (10 == n_dec) {
            if (nums[0] * nums[0] > 2 * 2) {
                return 0;
            }
        }
        int b = 1;
        int x2 = 0;
        int THE_MIN = 1 << 31;
        int THE_MAX = ~(THE_MIN);
        int danger_num = x > 0 ? THE_MAX : THE_MIN;
        for (int i = n_dec - 1; i >= 0; i--) {
            if (10 == n_dec) {
                danger_num -= nums[i] * b;
                if (x > 0 && danger_num < 0) {
                    return 0;
                }
                if (x < 0 && danger_num > 0) {
                    return 0;
                }
            }
            x2 += nums[i] * b;
            if (0 == i) {  // 永远不要忘了底数溢出
                break;
            }
            b *= 10;
        }

        return x2;
    }

    int reverse0(int x) {
        // corner case
        // 到另一个问题，如何确认边界
        int THE_MIN = 1 << 31;
        int THE_MAX = ~(1 << 31);  // 2147483648

        // 求位数
        int q = 10;
        int n_dec = 1;
        while (x / q) {
            n_dec++;
            if (10 == n_dec) {
                break;
            }
            q *= 10;
        }

        // 逆转
        int x2 = 0;
        int b = 10 == n_dec ? 1000000000 : q / 10, q2 = 1;
        // cout << "# " << n_dec << ", " << b << "\n";
        int resd = x;
        int danger_num = x > 0 ? THE_MAX : THE_MIN;
        while (b) {
            int num = resd / b;

            if (10 == n_dec) {
                // 可能会越界
                // 假设x > 0
                // cout << "#here\n";
                // cout << "#here " << b << ", " << num << "\n";
                if (1 == b && num * num > 4) {  // x^2 > a^2, |x| > |a|
                    // cout << "#here\n";
                    return 0;
                }
                danger_num -= num * q2;
                // cout << "#here " << b << ", " << num << ", " << danger_num <<
                // "\n";
                if (x > 0 && danger_num < 0) {
                    return 0;
                }
                if (x < 0 && danger_num > 0) {
                    return 0;
                }
            }

            resd -= num * b;
            x2 += num * q2;
            b /= 10;
            if (0 == b) {
                // 满位时，为了避免执行下面句子导致溢出
                break;
            }
            q2 *= 10;
        }

        return x2;
    }
};

int main() {
    Solution sol;
    int x;

    x = 123;
    cout << sol.reverse(x) << "\n";

    x = -123;
    cout << sol.reverse(x) << "\n";

    x = 120;
    cout << sol.reverse(x) << "\n";

    x = 1000000023;
    cout << sol.reverse(x) << "\n";

    x = 1000000022;
    cout << sol.reverse(x) << "\n";

    x = -1000000023;
    cout << sol.reverse(x) << "\n";

    x = -2147483412;
    cout << sol.reverse(x) << "\n";

    return 0;
}