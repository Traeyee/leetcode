// 转化为链表的那个解法我OK，现在试递归解法
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        // 情况一：p在left，q在right，返回root
        if (left && right) {
            return root;
        }
        // 情况二：p,q均在任一，返回那个结点
        if (left && !right) {
            return left;
        }
        if (!left && right) {
            return right;
        }
        // 情况三：p,q均不在，返回null
        if (!left && !right) {
            return nullptr;
        }

        return nullptr;
    }
};