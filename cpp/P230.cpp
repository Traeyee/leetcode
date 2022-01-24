/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   13 November 2020 14:08
 * @brief  最暴力的解法，把树内容全部拿出来，拿进最大堆，比top小的进，最后top就是要的，那么时间复杂度就是
 * O(n) + O(n) * O(logn) = O(nlogn)，和快排一样
 * 但它这里有二叉搜索树，如果我们能知道树含有的结点树就好了
 * 想法：建一棵同构的结点数树
 * 最后原来有更简洁的解法，不错
 */
#include <iostream>

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
  TreeNode *build_card_tree(TreeNode *val_tree) {
      if (!val_tree) {
          return nullptr;
      }
      auto card_tree = new TreeNode;
      card_tree->left = build_card_tree(val_tree->left);
      card_tree->right = build_card_tree(val_tree->right);
      card_tree->val = 1;
      if (card_tree->left) {
          card_tree->val += card_tree->left->val;
      }
      if (card_tree->right) {
          card_tree->val += card_tree->right->val;
      }
      return card_tree;
  }
  int findKthSmallest(TreeNode *val_tree, TreeNode *card_tree, int k) {
      // std::cout << val_tree->val << "," << card_tree->val << "," << k << "\n";
      if (card_tree->val == 1) {
          return val_tree->val;
      }
      int k2 = k;
      if (card_tree->left) {
          if (k <= card_tree->left->val) {
              return findKthSmallest(val_tree->left, card_tree->left, k);
          } else if (k == card_tree->left->val + 1) {
              return val_tree->val;
          }
          k2 -= card_tree->left->val;
      }
      if (k2 == 1) {
          return val_tree->val;
      }
      k2 -= 1;
      return findKthSmallest(val_tree->right, card_tree->right, k2);
  }
  int kthSmallest(TreeNode *root, int k) {
      auto card_tree = build_card_tree(root);
      return findKthSmallest(root, card_tree, k);
  }
};
int main() {
    auto x1 = new TreeNode(3);
    auto x2 = new TreeNode(1);
    auto x3 = new TreeNode(4);
    auto x4 = new TreeNode(2);
    x1->left = x2;
    x1->right = x3;
    x2->right = x4;
    Solution s;
    std::cout << s.kthSmallest(x1, 1);

    return 0;
}