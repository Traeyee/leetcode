/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-17 10:50
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
    bool isValidBST(TreeNode *root, int& min_val, int& max_val) {
        if (!root) {
            return true;
        }

        min_val = root->val, max_val = root->val;

        if (root->left) {
            if (root->left->val >= root->val) {
                return false;
            }
            int min_val1, max_val1;
            if (!isValidBST(root->left, min_val1, max_val1)) {
                return false;
            }
            if (max_val1 >= root->val) {
                return false;
            }
            min_val = min_val1 < min_val ? min_val1 : min_val;
        }
        if (root->right) {
            if (root->val >= root->right->val) {
                return false;
            }
            int min_val1, max_val1;
            if (!isValidBST(root->right, min_val1, max_val1)) {
                return false;
            }
            if (root->val >= min_val1) {
                return false;
            }
            max_val = max_val1 > max_val ? max_val1 : max_val;
        }

        return true;
    }
    bool isValidBST(TreeNode *root) {
        int tmp1, tmp2;
        return isValidBST(root, tmp1, tmp2);
    }
};