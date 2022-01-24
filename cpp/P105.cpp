#include <algorithm>
#include <iostream>
#include <queue>
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
    TreeNode* _buildTree(vector<int>& preorder, int pre_l, vector<int>& inorder,
                         int in_l, int in_r) {
        // edge case
        if (pre_l >= preorder.size() || in_l >= in_r) {
            return nullptr;
        }

        int root_val = preorder[pre_l];
        int root_index = -1;
        for (size_t i = in_l; i < in_r; i++) {
            if (root_val == inorder[i]) {
                root_index = i;
                break;
            }
        }

        auto left = _buildTree(preorder, pre_l + 1, inorder, in_l, root_index);
        auto right = _buildTree(preorder, pre_l + 1 + (root_index - in_l),
                                inorder, root_index + 1, in_r);
        return new TreeNode(root_val, left, right);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, 0, inorder, 0, inorder.size());
    }
};