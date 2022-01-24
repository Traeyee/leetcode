/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-11 17:52
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
    int countPrimes(int n) {
        vector<bool> is_prime(n + 1, true);

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            cnt += is_prime[i] ? 1 : 0;
            if (is_prime[i]) {
                cnt++;
                int max_factor = n / i;
                max_factor = i < max_factor ? i : max_factor;
                for (int j = 2; j <= max_factor; j++) {
                    is_prime[i * j] = false;
                }
            }
        }

        return cnt;
    }
    int countPrimes0(int n) {
        vector<bool> is_prime(n + 1, true);

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            cnt += is_prime[i] ? 1 : 0;
            int max_factor = n / i;
            // 避免提前与更大的数计算，相当于减少重复计算
            // max_factor = min({i, max_factor});
            // 712 ms	10.4 MB
            //
            // 380 ms	10.1 MB
            // 三目运算几乎节约了一半时间
            max_factor = i < max_factor ? i : max_factor;
            for (int j = 2; j <= max_factor; j++) {
                is_prime[i * j] = false;
            }
        }

        return cnt;
    }
};