/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-08 16:20
 * @brief  教训：对于那些复杂度大的题目，不要想着优化时间和空间，先做出再说
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

struct Node {
    int last_val, count;
    Node() { Node(0); }
    Node(int last_val) : last_val(last_val), count(1) {}
};

class Solution {
   public:
    bool isPossible(vector<int>& nums) {
        vector<Node> buckets;
        for (const auto& ele : nums) {
            if (buckets.empty()) {
                buckets.emplace_back(Node(ele));
                continue;
            }

            bool done = false;
            for (int i = buckets.size() - 1; i >= 0; i--) {
                if (buckets[i].last_val + 1 == ele) {
                    buckets[i].last_val++;
                    buckets[i].count++;
                    done = true;
                    break;
                } else if (buckets[i].last_val + 1 < ele) {
                    buckets.emplace_back(Node(ele));
                    done = true;
                    break;
                }
            }
            if (!done) {
                buckets.emplace_back(Node(ele));
            }
        }

        for (const auto& bucket : buckets) {
            if (bucket.count < 3) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 2, 3, 3, 4, 5};
    cout << sol.isPossible(nums) << "\n";

    nums = {1, 2, 3, 3, 4, 4, 5, 5};
    cout << sol.isPossible(nums) << "\n";

    nums = {1, 2, 3, 4, 4, 5};
    cout << sol.isPossible(nums) << "\n";

    return 0;
}