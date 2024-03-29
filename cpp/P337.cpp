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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int traverse12(TreeNode *node, unordered_map<TreeNode*, int>& memo) {
        if (!node) {
            return 0;
        }
        if (memo.end() != memo.find(node)) {
            return memo[node];
        }

        // 偷node
        int val1 = node->val;
        if (node->left) {
            val1 += traverse12(node->left->left, memo);
            val1 += traverse12(node->left->right, memo);
        }
        if (node->right) {
            val1 += traverse12(node->right->left, memo);
            val1 += traverse12(node->right->right, memo);
        }

        // 不偷node
        int val2 = traverse12(node->left, memo) + traverse12(node->right, memo);

        int res = val1 > val2 ? val1 : val2;
        memo[node] = res;
        return res;
    }
    int rob(TreeNode *root) {
        unordered_map<TreeNode*, int> memo;
        return traverse12(root, memo);
    }

    // 我的原始版本，用记录表table提高效率
    int traverse(TreeNode *root, bool rob_root,
                 unordered_map<TreeNode *, int> &table) {
        if (!root) {
            return 0;
        }

        if (rob_root) {
            int x1 = traverse(root->left, false, table);
            int x2 = traverse(root->right, false, table);
            int amount = root->val + x1 + x2;
            return amount;
        } else {
            int l0;
            if (table.end() != table.find(root->left)) {
                l0 = table[root->left];
            } else {
                int l1 = traverse(root->left, true, table);
                int l2 = traverse(root->left, false, table);
                l0 = l1 > l2 ? l1 : l2;
                table[root->left] = l0;
            }

            int r0;
            if (table.end() != table.find(root->right)) {
                r0 = table[root->right];
            } else {
                int r1 = traverse(root->right, true, table);
                int r2 = traverse(root->right, false, table);
                r0 = r1 > r2 ? r1 : r2;
                table[root->right] = r0;
            }

            int amount = l0 + r0;
            return amount;
        }
    }

    int traverse2(TreeNode *root, bool rob_root,
                  unordered_map<TreeNode *, int> &table) {
        if (!root) {
            return 0;
        }

        if (rob_root) {
            int x1 = traverse(root->left, false, table);
            int x2 = traverse(root->right, false, table);
            int amount = root->val + x1 + x2;
            return amount;
        } else {
            int l0;
            if (table.end() != table.find(root->left)) {
                l0 = table[root->left];
            } else {
                int l1 = traverse(root->left, true, table);
                int l2 = traverse(root->left, false, table);
                l0 = l1 > l2 ? l1 : l2;
                table[root->left] = l0;
            }

            int r0;
            if (table.end() != table.find(root->right)) {
                r0 = table[root->right];
            } else {
                int r1 = traverse(root->right, true, table);
                int r2 = traverse(root->right, false, table);
                r0 = r1 > r2 ? r1 : r2;
                table[root->right] = r0;
            }

            int amount = l0 + r0;
            return amount;
        }
    }

    int rob0(TreeNode *root) {
        unordered_map<TreeNode *, int> table = {{NULL, 0}};
        int x1 = traverse(root, true, table);
        int x2 = traverse(root, false, table);

        return x1 > x2 ? x1 : x2;
    }
};

int main() {
    Solution s;
    return 0;
}