#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int _numTrees(int lbound, int rbound, unordered_map<string, int>& memo) {
        // corner case
        int n = rbound - lbound;
        if (0 == n) {
            return 1;
        } else if (1 == n || 2 == n) {
            return n;
        }

        stringstream ss;
        ss << lbound << "-" << rbound;
        string key = ss.str();
        if (memo.end() != memo.find(key)) {
            return memo[key];
        }

        int num = 0;
        for (int i = lbound; i < rbound; i++) {
            int ln = _numTrees(lbound, i, memo);
            int rn = _numTrees(i + 1, rbound, memo);
            num += ln * rn;
        }
        memo[key] = num;
        return num;
    }
    int numTrees(int n) {
        unordered_map<string, int> memo;
        return _numTrees(0, n, memo);
    }
};