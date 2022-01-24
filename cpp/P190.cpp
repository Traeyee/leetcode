/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-28 19:53
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
    uint32_t reverseBits(uint32_t n) {
        if (0 == n) {
            return 0;
        }
        uint32_t res = 0;
        uint32_t n1 = n;
        uint32_t cnt = 0;
        while (n1) {
            uint32_t r = n1 & 1;
            res = (res << 1) + r;
            n1 >>= 1;
            cnt++;
        }
        res <<= 32 - cnt;
        return res;
    }
};

int main() {
    Solution sol;
    uint32_t n;

    n = 43261596;
    cout << sol.reverseBits(n) << "\n";

    n = 4294967293;
    cout << sol.reverseBits(n) << "\n";

    return 0;
}