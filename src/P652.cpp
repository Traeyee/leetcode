#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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

// 学到：因为x序遍历没有表示空结点，所有要表示一棵树需要至少两种序列
// 前序遍历和后序遍历还原二叉树 已知前序和中序,后序和中序遍历序列之后,可以唯一确定一棵二叉树。但是,只知道前序和后序遍历序列,是无法分辨哪个结点是左子树或右子树
// 但这里的序列可以用#表示空结点，所以只需要一个序列就可以了
class Solution {
   public:
    pair<string, string> _findDuplicateSubtrees(
        TreeNode* root, unordered_map<string, int>& key_map,
        vector<TreeNode*>& dups) {
        if (!root) {
            return make_pair("#-", "#-");
        }
        stringstream pre_ss, in_ss;
        pre_ss << root->val << '-';

        auto l_p = _findDuplicateSubtrees(root->left, key_map, dups);
        string l_pre = l_p.first, l_in = l_p.second;
        string l_key = l_pre + "+" + l_in;
        pre_ss << l_pre;
        in_ss << l_in;
        if (root->left) {
            if (1 == key_map[l_key]) {
                dups.emplace_back(root->left);
            }
            key_map[l_key]++;
        }

        in_ss << root->val << '-';

        auto r_p = _findDuplicateSubtrees(root->right, key_map, dups);
        string r_pre = r_p.first, r_in = r_p.second;
        string r_key = r_pre + "+" + r_in;
        pre_ss << r_pre;
        in_ss << r_in;
        if (root->right) {
            if (1 == key_map[r_key]) {
                dups.emplace_back(root->right);
            }
            key_map[r_key]++;
        }

        return make_pair(pre_ss.str(), in_ss.str());
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> key_map;
        vector<TreeNode*> dups;
        _findDuplicateSubtrees(root, key_map, dups);
        return dups;
    }
};