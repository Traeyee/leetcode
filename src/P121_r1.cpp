/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-17 19:59
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
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - min_price;
            max_profit = profit > max_profit ? profit : max_profit;
            min_price = prices[i] < min_price ? prices[i] : min_price;
        }

        return max_profit;
    }
};

int main() {
    Solution s;
    vector<int> prices;

    prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << "\n";

    prices = {7, 6, 4, 3, 1};
    cout << s.maxProfit(prices) << "\n";

    return 0;
}