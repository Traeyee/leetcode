/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   23 November 2020 22:36
 * @brief  
 */
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* _sortedArrayToBST(vector<int>& nums, int l, int r) {
      if (l > r) {
          return nullptr;
      }

      int m = (l + r) / 2;
      auto root = new TreeNode(nums[m]);
      root->left = _sortedArrayToBST(nums, l, m - 1);
      root->right = _sortedArrayToBST(nums, m + 1, r);

      return root;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
      return _sortedArrayToBST(nums, 0, nums.size() - 1);
  }
};