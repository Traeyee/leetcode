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
    vector<TreeNode*> _generateTrees(int lbound, int rbound) {
        int n = rbound - lbound;
        if (0 == n) {
            return {nullptr};
        } else if (1 == n) {
            return {new TreeNode(lbound + 1)};
        }

        vector<TreeNode*> possible_trees;

        for (int i = lbound; i < rbound; i++) {
            auto left_trees = _generateTrees(lbound, i);
            auto right_trees = _generateTrees(i + 1, rbound);
            for (const auto& lt : left_trees) {
                for (const auto& rt : right_trees) {
                    auto new_tree = new TreeNode(i + 1, lt, rt);
                    possible_trees.emplace_back(new_tree);
                }
            }
        }

        return possible_trees;
    }
    vector<TreeNode*> generateTrees(int n) { return _generateTrees(0, n); }
};