/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-10-30 15:55
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
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0;
        for (int num : piles) {
            l += num / h;
        }
        l = 1 > l ? 1 : l;
        int r = *max_element(piles.begin(), piles.end());
        int min_k = r;

        // l = 0, r = 1
        while (l <= r) {
            int k = (r - l) / 2 + l;
            // cout << "# " << l << ", " << k << ", " << r << '\n';
            int h1 = h;
            for (int num : piles) {
                double tmp = (double)num / k;
                h1 -= ceil(tmp);
                if (h1 < 0) {
                    l = k + 1;
                    break;
                }
            }
            if (h1 >= 0) {
                min_k = k < min_k ? k : min_k;
                r = k - 1;
            }
        }

        return min_k;
    }
};

int main() {
    Solution sol;
    vector<int> piles;
    int h;

    // piles = {3, 6, 7, 11}, h = 8;
    // cout << sol.minEatingSpeed(piles, h) << '\n';

    // piles = {30, 11, 23, 4, 20}, h = 5;
    // cout << sol.minEatingSpeed(piles, h) << '\n';

    // piles = {30, 11, 23, 4, 20}, h = 6;
    // cout << sol.minEatingSpeed(piles, h) << '\n';

    // piles = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293,
    //          112677673, 679580077, 337406589, 290818316, 877337160, 901728858,
    //          679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    // h = 823855818;
    // cout << sol.minEatingSpeed(piles, h) << '\n';

    piles = {312884470}, h = 968709470;
    cout << sol.minEatingSpeed(piles, h) << '\n';

    return 0;
}