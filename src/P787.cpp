/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-04 17:13
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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        int THE_MAX = pow(10, 6);
        vector<vector<int>> dp(n, vector<int>(k + 1, THE_MAX));
        vector<vector<int>> adj(n, vector<int>(n, THE_MAX));
        bool found = false;
        unordered_set<int> candidates = {src};
        for (const auto& flight : flights) {
            adj[flight[0]][flight[1]] = flight[2];
            if (flight[0] == src) {
                dp[flight[1]][0] = flight[2];
                candidates.insert(flight[1]);
                if (dst == flight[1]) {
                    found = true;
                }
            }
        }
        dp[src][0] = 0;

        for (int k1 = 1; k1 <= k; k1++) {
            dp[src][k1] = 0;
            for (int i = 0; i < n; i++) {
                if (candidates.end() == candidates.find(i)) {
                    continue;
                }
                if (dp[i][k1 - 1] >= THE_MAX) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if (adj[i][j] < THE_MAX) {
                        int cost2 = dp[i][k1 - 1] + adj[i][j];
                        if (cost2 < dp[j][k1]) {
                            // cout << "#" << i << "," << j << ",k=" << k1 << ":"
                            //      << dp[j][k1] << "-->" << cost2 << "\n";
                            dp[j][k1] = cost2;
                            candidates.insert(j);
                            if (dst == j) {
                                found = true;
                            }
                        }
                    }
                }
            }
        }

        if (!found) {
            return -1;
        }
        return dp[dst][k];
    }
};

int main() {
    Solution s;
    vector<vector<int>> flights;
    int n, src, dst, k;

    n = 4, src = 3, dst = 0, k = 1;
    flights = {{1, 0, 1}, {2, 0, 5}, {2, 1, 1}, {3, 2, 1}};
    cout << s.findCheapestPrice(n, flights, src, dst, k) << "\n";

    return 0;
}