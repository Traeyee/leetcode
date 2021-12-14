/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-17 10:45
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
    void inorderTraversal(TreeNode *root, vector<int>& output) {
        if (!root) {
            return;
        }

        inorderTraversal(root->left, output);
        output.emplace_back(root->val);
        inorderTraversal(root->right, output);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> output;
        inorderTraversal(root, output);
        return output;
    }
};