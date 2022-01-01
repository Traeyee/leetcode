/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-14 22:05
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
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            int shorter = height[l] < height[r] ? height[l] : height[r];
            int area = shorter * (r - l);
            res = area > res ? area : res;

            if (height[l] < height[r]) {
                int l1 = l + 1;
                while (l1 < r && height[l] > height[l1]) {
                    l1++;
                }
                l = l1;
            } else {
                int r1 = r - 1;
                while (l < r1 && height[r1] < height[r]) {
                    r1--;
                }
                r = r1;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> height;

    height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(height) << '\n';

    height = {1, 1};
    cout << sol.maxArea(height) << '\n';

    height = {4, 3, 2, 1, 4};
    cout << sol.maxArea(height) << '\n';

    height = {1, 2, 1};
    cout << sol.maxArea(height) << '\n';

    return 0;
}