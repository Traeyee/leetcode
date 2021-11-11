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
        vector<int> surplus;
        for (int i = 0; i < n; i++) {
            surplus.emplace_back(gas[i] - cost[i]);
        }

        
    }
};