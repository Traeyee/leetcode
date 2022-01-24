/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-09 21:33
 * @brief  TL;
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
   // 极值法，O(n)，我想出来的
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        int max_h = *max_element(height.begin(), height.end());
        int max_idx1 = -1, max_idx2;
        for (int i = 0; i < n; i++) {
            if (height[i] == max_h) {
                if (-1 == max_idx1) {
                    max_idx1 = i;
                }
                max_idx2 = i;
            }
        }
        vector<int> extrm;
        int cur_h = 0;
        for (int i = 0; i < max_idx1; i++) {
            if (height[i] >= cur_h) {
                cur_h = height[i];
                extrm.emplace_back(i);
            }
        }
        extrm.emplace_back(max_idx1);
        if (max_idx2 != max_idx1) {
            extrm.emplace_back(max_idx2);
        }
        cur_h = 0;
        stack<int> stk;
        for (int i = n - 1; i > max_idx2; i--) {
            if (height[i] >= cur_h) {
                cur_h = height[i];
                stk.push(i);
            }
        }
        while (!stk.empty()) {
            extrm.emplace_back(stk.top());
            stk.pop();
        }

        int v = 0;
        for (int k = 0; k < extrm.size() - 1; k++) {
            int idx1 = extrm[k], idx2 = extrm[k + 1];
            if (idx2 - idx1 >= 2) {
                int h = min({height[idx1], height[idx2]});
                for (int i = idx1 + 1; i <= idx2 - 1; i++) {
                    v += h - height[i];
                }
                // cout << "# " << idx1 << "-" << idx2 << ": " << v - v1 << "\n";
            }
        }

        return v;
    }

    // 错误代码，但是思考过程
    int trap1(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        vector<int> extrm;
        if (height[0] >= height[1]) {
            extrm.emplace_back(0);
        }
        for (int i = 1; i < n - 1; i++) {
            if (height[i - 1] <= height[i] && height[i] >= height[i + 1]) {
                extrm.emplace_back(i);
            }
        }
        if (height[n - 2] <= height[n - 1]) {
            extrm.emplace_back(n - 1);
        }

        int v = 0;
        for (int k = 0; k < extrm.size() - 1; k++) {
            int idx1 = extrm[k], idx2 = extrm[k + 1];
            if (idx2 - idx1 >= 2) {
                int h = min({height[idx1], height[idx2]});
                int v1 = v;
                v += h * (idx2 - idx1 - 1);
                for (int i = idx1 + 1; i <= idx2 - 1; i++) {
                    v -= min({h, height[i]});
                }
                cout << "# " << idx1 << "-" << idx2 << ": " << v - v1 << "\n";
            }
        }

        return v;
    }

    // TL了，时间复杂度太高
    int trap0(vector<int>& height) {
        int n = height.size();
        int max_h = *max_element(height.begin(), height.end());

        int v = 0;
        for (int h = 1; h <= max_h; h++) {
            int state = 0;
            int v_tmp = 0;
            for (int i = 0; i < n; i++) {
                if (0 == state) {  // 左边为空
                    if (height[i] >= h) {
                        state = 1;
                    }
                } else {
                    if (height[i] < h) {
                        v_tmp++;
                    } else {
                        // cout << "# " << h << ", " << i << ":" << v_tmp <<
                        // "\n";
                        v += v_tmp;
                        v_tmp = 0;
                    }
                }
            }
        }

        return v;
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