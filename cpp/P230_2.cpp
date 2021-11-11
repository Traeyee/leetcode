#include <algorithm>
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
    vector<int> get_inorder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> inorder;
        auto left_inorder = get_inorder(root->left);
        inorder.insert(inorder.end(), left_inorder.begin(), left_inorder.end());
        inorder.emplace_back(root->val);
        auto right_inorder = get_inorder(root->right);
        inorder.insert(inorder.end(), right_inorder.begin(), right_inorder.end());
        return inorder;
    }
    int kthSmallest(TreeNode* root, int k) {
        auto inorder = get_inorder(root);
        return inorder[k - 1];
    }
};