/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-07 11:26
 * @brief  最简单的当然是暴力破解
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int min_idx = -1, min_balance = 0;
        for (int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];
            if (balance < min_balance) {
                min_balance = balance;
                min_idx = i;
            }
        }

        if (-1 == min_idx) {
            return -1;
        }
        min_idx = (min_idx + 1) % n;
        balance = 0;
        for (int i = 0; i < n; i++) {
            int idx = (min_idx + i) % n;
            balance += gas[idx] - cost[idx];
        }
        if (balance >= 0) {
            return min_idx;
        }
        return -1;
    }
};