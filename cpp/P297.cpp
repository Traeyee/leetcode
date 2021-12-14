/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-01 14:33
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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        while (q.size() > 0) {
            auto node = q.front();
            if (node) {
                ss << node->val;
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << '#';
            }
            ss << '\t';
            q.pop();
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (0 == data.size()) {
            return nullptr;
        }
        auto splits = split(data, "\t");
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(atoi(splits[0].c_str()));
        q.emplace(root);
        int i = 1;
        while (i < splits.size() && q.size() > 0) {
            auto node = q.front();
            if (i < splits.size() && splits[i] != "#") {
                int val = atoi(splits[i].c_str());
                TreeNode* node2 = new TreeNode(val);
                node->left = node2;
                q.push(node2);
            }
            i++;
            if (i < splits.size() && splits[i] != "#") {
                int val = atoi(splits[i].c_str());
                TreeNode* node2 = new TreeNode(val);
                node->right = node2;
                q.push(node2);
            }
            i++;
            q.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));