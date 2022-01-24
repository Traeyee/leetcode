/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-14 13:46
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int get_max_depth(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }
        int ld = get_max_depth(root->left, diameter);
        int rd = get_max_depth(root->right, diameter);
        int d1 = ld + 1 + rd - 1;
        if (d1 > diameter) {
            diameter = d1;
        }
        return 1 + (ld > rd ? ld : rd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        get_max_depth(root, diameter);
        return diameter;
    }
};