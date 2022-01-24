/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-11 15:44
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
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
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int a_i, a_i_1 = 2, a_i_2 = 1;
        for (int i = 2; i < n; i++) {
            a_i = a_i_1 + a_i_2;
            a_i_2 = a_i_1;
            a_i_1 = a_i;
        }
        return a_i;
    }
};