/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-13 15:10
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
    bool stoneGame__FALSE(vector<int>& piles, int l, int r, int turn,
                   vector<int>& sums, unordered_map<string, bool>& memo) {
        int next_turn = turn ^ 1;
        if (l > r) {
            return sums[turn] > sums[next_turn];
        }

        // 这个是错的
        stringstream ss;
        ss << l << '-' << r << '-' << turn;
        string key = ss.str();
        if (memo.end() != memo.find(key)) {
            return memo[key];
        }

        // take l
        sums[turn] += piles[l];
        bool res1 = stoneGame(piles, l + 1, r, next_turn, sums, memo);
        sums[turn] -= piles[l];
        // if (!res1) {  // 提前截断
        //     return true;
        // }

        // take r
        sums[turn] += piles[r];
        bool res2 = stoneGame(piles, l, r - 1, next_turn, sums, memo);
        sums[turn] -= piles[r];

        bool res = !res1 || !res2;
        memo[key] = res;
        return res;
    }

    bool stoneGame(vector<int>& piles) {
        vector<int> sums = {0, 0};
        unordered_map<string, bool> memo;
        return stoneGame(piles, 0, piles.size() - 1, 0, sums, memo);
    }
};

int main() {
    Solution sol;
    vector<int> piles;

    piles = {5, 3, 4, 5};
    cout << sol.stoneGame(piles) << "\n";

    piles = {3, 7, 2, 3};
    cout << sol.stoneGame(piles) << "\n";

    piles = {10, 3, 1, 7, 8, 6, 8, 10};
    cout << sol.stoneGame(piles) << "\n";

    return 0;
}