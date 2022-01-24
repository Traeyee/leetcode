/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-06 22:26
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
    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        TreeNode *cur_node = root;
        stack<pair<TreeNode *, int>> stk;
        stk.emplace(root, 1);

        int last_leaf_d = -1;
        int visit_leaf_cnt = 0;
        int max_d = 0;
        while (stk.size() > 0) {
            auto cur_node = stk.top().first;
            int d = stk.top().second;

            while (cur_node->right) {
                d++;
                stk.emplace(cur_node->left, d);
                cur_node = cur_node->right;
            }
            max_d = d > max_d ? d : max_d;
            if (cur_node->left) {
                // 这里是分界点
                max_d = d + 1;
                cout << "#1: " << max_d << ", " << visit_leaf_cnt << '\n';
                return (1 << max_d) - 1 - visit_leaf_cnt - 1;
            } else {
                // 到了叶结点
                if (-1 == last_leaf_d) {
                    last_leaf_d = d;
                }
                if (d != last_leaf_d) {
                    // 如果和老d不等，则是跨父的分界点
                    cout << "#2: " << max_d << ", " << visit_leaf_cnt << '\n';
                    return (1 << max_d) - 1 - visit_leaf_cnt;
                } else {
                    // 如果相等
                    visit_leaf_cnt++;
                }
            }
            stk.pop();
        }

        return (1 << max_d) - 1;
    }
};