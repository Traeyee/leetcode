/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-28 20:07
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
    int hammingWeight(uint32_t n) {
        uint32_t n1 = n;
        int16_t cnt = 0;
        while (n1) {
            cnt += n1 & 1;
            n1 >>= 1;
        }
        return cnt;
    }
};
