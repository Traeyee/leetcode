/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-15 16:17
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
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](vector<int>& x1, vector<int>& x2) {
            if (x1[0] == x2[0]) {
                return x1[1] < x2[1];
            }
            return x1[0] < x2[0];
        };
        sort(points.begin(), points.end(), cmp);

        int last_shot = points[0][1];
        int n_shots = 1;
        for (int i = 1; i < points.size(); i++) {
            auto& point = points[i];
            if (point[0] <= last_shot) {
                last_shot = point[1] < last_shot ? point[1] : last_shot;
            } else {
                n_shots++;
                last_shot = point[1];
            }
        }

        return n_shots;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points;

    points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << sol.findMinArrowShots(points) << "\n";

    points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << sol.findMinArrowShots(points) << "\n";

    points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << sol.findMinArrowShots(points) << "\n";

    points = {{1, 2}};
    cout << sol.findMinArrowShots(points) << "\n";

    points = {{2, 3}, {2, 3}};
    cout << sol.findMinArrowShots(points) << "\n";

    return 0;
}