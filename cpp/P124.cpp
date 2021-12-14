/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-17 20:53
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
    // max_sum: 两儿子都可以连的话，max_sum（至少一个结点）
    int maxPathSum(TreeNode *root, int &max_sum) {
        vector<int> res = {root->val}, max_sum_res = {root->val};

        int l_max_sum0, r_max_sum0, l_max_sum1, r_max_sum1;
        if (root->left) {
            l_max_sum0 = maxPathSum(root->left, l_max_sum1);
            max_sum_res.emplace_back(l_max_sum0);
            max_sum_res.emplace_back(l_max_sum0 + root->val);
            max_sum_res.emplace_back(l_max_sum1);
            res.emplace_back(l_max_sum0 + root->val);
        }
        if (root->right) {
            r_max_sum0 = maxPathSum(root->right, r_max_sum1);
            max_sum_res.emplace_back(r_max_sum0);
            max_sum_res.emplace_back(r_max_sum0 + root->val);
            max_sum_res.emplace_back(r_max_sum1);
            res.emplace_back(r_max_sum0 + root->val);
        }
        if (root->left && root->right) {
            max_sum_res.emplace_back(l_max_sum0 + root->val + r_max_sum0);
        }
        max_sum = *max_element(max_sum_res.begin(), max_sum_res.end());

        // max_sum = max({
        //     root->val,
        //     l_max_sum0,  // 只左儿子
        //     r_max_sum0,  // 只右儿子
        //     l_max_sum0 + root->val,
        //     root->val + r_max_sum0,
        //     l_max_sum0 + root->val + r_max_sum0,  // 三点相连
        //     l_max_sum1,  // 左儿子下的max_sum
        //     r_max_sum1  // 右儿子下的max_sum
        // });
        // ret = max({
        //     root->val, l_max_sum0 + root->val, root->val + r_max_sum0
        // });

        // cout << "# here1: " << root->val << "\n";
        // for (auto ele : max_sum_res) {
        //     cout << ele << ", ";
        // }
        // cout << "\n";
        // cout << "# here2: " << root->val << "\n";
        // for (auto ele : res) {
        //     cout << ele << ", ";
        // }
        // cout << "\n";
        return *max_element(res.begin(), res.end());
    }
    int maxPathSum(TreeNode *root) {
        int max_sum1;
        int max_sum2 = maxPathSum(root, max_sum1);
        return max_sum1 > max_sum2 ? max_sum1 : max_sum2;
    }
};