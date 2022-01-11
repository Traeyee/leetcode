/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-04 10:14
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
   public:
    TreeNode *inorder_last(TreeNode *root) {
        if (!root) {
            return root;
        }
        auto last = inorder_last(root->right);
        return last ? last : root;
    }
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p) {
        if (!root || !p) {
            return nullptr;
        }

        if (p->val < root->val) {
            return inorderPredecessor(root->left, p);
        } else if (p->val > root->val) {
            auto last = inorderPredecessor(root->right, p);
            return last ? last : root;
        }
        return inorder_last(root->left);
    }
};