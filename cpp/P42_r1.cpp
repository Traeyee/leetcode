/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-14 22:25
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
    // 空间优化版
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> lmax = {height[0]};
        for (int i = 1; i < n; i++) {
            lmax.emplace_back(lmax[i - 1] > height[i] ? lmax[i - 1]
                                                      : height[i]);
        }

        int water = 0;
        int rmax = height[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int lower = lmax[i - 1] < rmax ? lmax[i - 1] : rmax;
            if (lower > height[i]) {
                water += lower - height[i];
            }
            rmax = height[i] > rmax ? height[i] : rmax;
        }

        return water;
    }
    int trap0(vector<int>& height) {
        int n = height.size();

        vector<int> lmax = {height[0]}, rmax = {height[n - 1]};
        for (int i = 1; i < n; i++) {
            lmax.emplace_back(lmax[i - 1] > height[i] ? lmax[i - 1]
                                                      : height[i]);
        }
        for (int i = 1; i < n; i++) {
            rmax.emplace_back(rmax[i - 1] > height[n - 1 - i] ? rmax[i - 1]
                                                      : height[n - 1 - i]);
        }

        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            int lower = lmax[i - 1] < rmax[n - 1 - (i + 1)] ? lmax[i - 1] : rmax[n - 1 - (i + 1)];
            if (lower > height[i]) {
                // cout << "# " << i << ", " << lmax[i - 1] << ", " << rmax[n - 1 - (i + 1)] << '\n';
                water += lower - height[i];
            }
        }

        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height;

    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(height) << "\n";

    height = {4, 2, 0, 3, 2, 5};
    cout << sol.trap(height) << "\n";

    height = {5, 4, 1, 2};
    cout << sol.trap(height) << "\n";

    height = {4, 2, 0, 3, 2, 4, 3, 4};
    cout << sol.trap(height) << "\n";

    return 0;
}