/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-04 11:00
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class BSTIterator {
   public:
    BSTIterator(TreeNode *root) {
        if (root) {
            stk_.emplace(root, true);
        }
    }

    int next() {
        TreeNode *root = stk_.top().first;
        bool should_traverse = stk_.top().second;
        stk_.pop();
        if (should_traverse) {
            return traverse(root);
        }
        return root->val;
    }

    bool hasNext() { return stk_.size() > 0; }

   private:
    int traverse(TreeNode *root) {
        if (root->right) {
            stk_.emplace(root->right, true);
        }
        if (root->left) {
            stk_.emplace(root, false);
            return traverse(root->left);
        }
        return root->val;
    }
    stack<pair<TreeNode *, bool>> stk_;
};