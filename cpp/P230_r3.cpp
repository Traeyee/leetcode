/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-06 15:59
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
    int _kthSmallest(TreeNode *root, int k, bool& found, int &res) {
        if (!root) {
            return 0;
        }

        int l_n = _kthSmallest(root->left, k, found, res);
        if (found) {
            return 0;
        }      
        if (l_n == k - 1) {
            res = root->val;
            found = true;
            return 0;
        }
        return l_n + 1 + _kthSmallest(root->right, k - (l_n + 1), found, res);
    }

    int kthSmallest(TreeNode *root, int k) {
        bool found = false;
        int res;
        _kthSmallest(root, k, found, res);
        return res;
    }
};