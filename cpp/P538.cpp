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

class Solution {
   public:
    void _convertBST(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }

        _convertBST(root->right, sum);
        sum += root->val;
        root->val = sum;
        _convertBST(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        _convertBST(root, sum);
        return root;
    }
};