#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    tuple<bool, int, int, int> _maxSumBST(TreeNode* root, int& max_sum) {
        if (!root) {
            return {true, 0, 0, 0};
        }

        bool is_valid = true;
        int sum = root->val, min_val = root->val, max_val = root->val;
        if (root->left) {
            auto ret1 = _maxSumBST(root->left, max_sum);
            int min_val1 = get<2>(ret1), max_val1 = get<3>(ret1);
            is_valid &= get<0>(ret1) && (max_val1 < root->val);
            min_val = min_val < min_val1 ? min_val : min_val1;
            max_val = max_val > max_val1 ? max_val : max_val1;
            sum += get<1>(ret1);
        }
        if (root->right) {
            auto ret1 = _maxSumBST(root->right, max_sum);
            int min_val1 = get<2>(ret1), max_val1 = get<3>(ret1);
            is_valid &= get<0>(ret1) && (root->val < min_val1);
            min_val = min_val < min_val1 ? min_val : min_val1;
            max_val = max_val > max_val1 ? max_val : max_val1;
            sum += get<1>(ret1);
        }

        if (is_valid && sum > max_sum) {
            max_sum = sum;
        }

        return {is_valid, sum, min_val, max_val};
    }

    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        _maxSumBST(root, max_sum);
        return max_sum;
    }
};