#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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
    bool _isValidBST(TreeNode* root, int& min_val, int& max_val) {
        if (!root) {
            return true;
        }

        bool is_valid = true;
        min_val = root->val;
        max_val = root->val;
        if (root->left) {
            int min_val1, max_val1;
            bool l_ret = _isValidBST(root->left, min_val1, max_val1);
            is_valid &= l_ret && (max_val1 < root->val);
            min_val = min_val < min_val1 ? min_val : min_val1;
            max_val = max_val > max_val1 ? max_val : max_val1;
        }
        if (root->right) {
            int min_val1, max_val1;
            bool r_ret = _isValidBST(root->right, min_val1, max_val1);
            is_valid &= r_ret && (root->val < min_val1);
            min_val = min_val < min_val1 ? min_val : min_val1;
            max_val = max_val > max_val1 ? max_val : max_val1;
        }

        return is_valid;
    }

    bool isValidBST(TreeNode* root) {
        int min_val, max_val;
        return _isValidBST(root, min_val, max_val);
    }
};