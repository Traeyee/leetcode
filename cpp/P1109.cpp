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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // int diff[n];  // diff[i] = a[i] - a[i - 1], diff[0] = a[0]
        vector<int> diff(n, 0);

        for (const auto& booking : bookings) {
            auto first = booking[0] - 1;
            auto last = booking[1] - 1;
            auto seats = booking[2];
            diff[first] += seats;
            if (last < n - 1) {
                diff[last + 1] -= seats;
            }
        }

        for (size_t i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
};