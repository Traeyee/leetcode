/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-03 23:50
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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return root;
        }
        if (p->val == root->val || q->val == root->val) {
            return root;
        }

        if (p->val < root->val) {
            if (root->val < q->val) {
                return root;
            } else {
                return lowestCommonAncestor(root->left, p, q);
            }
        } else {
            if (root->val <= q->val) {
                return lowestCommonAncestor(root->right, p, q);
            } else {
                return root;
            }
        }

        return nullptr;
    }
};