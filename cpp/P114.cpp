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
    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }

        flatten(root->left);
        flatten(root->right);
        auto tmp_p = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode *p = new TreeNode;
        p->right = root;
        while (p->right) {
            p = p->right;
        }
        p->right = tmp_p;

        return;
    }
};