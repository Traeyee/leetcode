/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-17 19:37
 * @brief
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
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (nullptr == left && nullptr == right) {
            return true;
        }
        if (nullptr == left || nullptr == right) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
};
