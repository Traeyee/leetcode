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
    bool _isValidBST(TreeNode* root, int lbound, bool hard_l, int hbound, bool hard_h) {
        if (!root) {
            return true;
        }

        if (lbound > root->val) {
            return false;
        } else if (lbound == root->val && hard_l) {
            return false;
        }
        if (root->val > hbound) {
            return false;
        } else if (hbound == root->val && hard_h) {
            return false;
        }

        return _isValidBST(root->left, lbound, hard_l, root->val, true) &&
               _isValidBST(root->right, root->val, true, hbound, hard_h);
    }
    
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, INT_MIN, false, INT_MAX, false);
    }
};