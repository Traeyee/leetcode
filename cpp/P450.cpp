/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-06 16:35
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *merge(TreeNode *left, TreeNode *right) {
        TreeNode *root;
        if (left) {
            TreeNode *ptr = left, *last_ptr = nullptr;
            while (ptr->right) {
                last_ptr = ptr;
                ptr = ptr->right;
            }
            root = ptr;
            if (last_ptr) {
                last_ptr->right = nullptr;
            }
        } else if (right) {
            TreeNode *ptr = right, *last_ptr = nullptr;
            while (ptr->left) {
                last_ptr = ptr;
                ptr = ptr->left;
            }
            root = ptr;
            if (last_ptr) {
                last_ptr->left = nullptr;
            }
        } else {
            return nullptr;
        }
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode *deleteNode__FALSE(TreeNode *root, int key) {
        if (!root) {
            return nullptr;
        }
        if (key == root->val) {
            return merge(root->left, root->right);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

