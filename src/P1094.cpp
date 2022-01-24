/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-08 15:25
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int max_len = 0;
        for (const auto& v : trips) {
            max_len = v[2] > max_len ? v[2] : max_len;
        }
        vector<int> diff(max_len + 1, 0);  // diff[i]: [i, i + 1] - [i - 1, i];
        for (const auto& v : trips) {
            int np = v[0], from = v[1], to = v[2];  // [from, to]
            diff[from] += np;
            diff[to] -= np;
        }
        int ai = 0;
        for (int i = 0; i < max_len; i++) {
            ai += diff[i];
            if (ai > capacity) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> trips;
    int capacity;

    trips = {{2, 1, 5}, {3, 3, 7}}, capacity = 4;
    cout << sol.carPooling(trips, capacity) << '\n';

    trips = {{2, 1, 5}, {3, 3, 7}}, capacity = 5;
    cout << sol.carPooling(trips, capacity) << '\n';

    trips = {{2, 1, 5}, {3, 5, 7}}, capacity = 3;
    cout << sol.carPooling(trips, capacity) << '\n';

    trips = {{3, 2, 7}, {3, 7, 9}, {8, 3, 9}}, capacity = 11;
    cout << sol.carPooling(trips, capacity) << '\n';

    return 0;
}