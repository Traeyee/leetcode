#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define max(x1, x2) (x1 < x2 ? x2 : x1)

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (0 == k || 0 == n) {
            return 0;
        }

        int dp[k + 1][n][2];
        for (int i = 0; i < n; i++) {
            dp[0][i][0] = 0;
            dp[0][i][1] = -0x3f3f3f3f;
        }
        for (int l = 1; l <= k; l++) {
            dp[l][0][0] = 0;
            dp[l][0][1] = -prices[0];
            for (int i = 1; i < n; i++) {
                dp[l][i][0] = max(dp[l][i - 1][0], dp[l][i - 1][1] + prices[i]);
                dp[l][i][1] =
                    max(dp[l][i - 1][1], dp[l - 1][i - 1][0] - prices[i]);
            }
        }

        return dp[k][n - 1][0];
    }
};

int main() {
    vector<int> prices = {2, 4, 1};
    Solution s;
    cout << s.maxProfit(2, prices) << "\n";

    prices = {3, 2, 6, 5, 0, 3};
    cout << s.maxProfit(2, prices) << "\n";

    return 0;
}