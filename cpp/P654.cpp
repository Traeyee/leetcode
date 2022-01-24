#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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
    TreeNode *_constructMaximumBinaryTree(vector<int> &nums, int lbound, int rbound) {
        if (lbound >= rbound) {
            return nullptr;
        }

        int pos = -1, max_val = -1;
        for (size_t i = lbound; i < rbound; i++) {
            if (nums[i] > max_val) {
                pos = i;
                max_val = nums[i];
            }
        }

        auto left = _constructMaximumBinaryTree(nums, lbound, pos);
        auto right = _constructMaximumBinaryTree(nums, pos + 1, rbound);
        return new TreeNode(max_val, left, right);
    }


    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return _constructMaximumBinaryTree(nums, 0, nums.size());
    }
};