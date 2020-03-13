#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (nullptr == root) {
            return ret;
        }
        queue<int> depth_q = queue<int>({0});
        queue<Node*> node_q = queue<Node*>({root});
        int current_depth = 0;
        vector<int> same_level_nodes;
        while (node_q.size() > 0) {
            auto node = node_q.front();
            node_q.pop();
            auto depth = depth_q.front();
            depth_q.pop();
            if (current_depth != depth) {
                ret.emplace_back(same_level_nodes);
                same_level_nodes.clear();
                current_depth = depth;
            }
            same_level_nodes.emplace_back(node->val);
            for (const auto& child : node->children) {
                node_q.push(child);
                depth_q.push(depth + 1);
            }
        }
        ret.emplace_back(same_level_nodes);
        return ret;
    }
};

int main() {
    Solution s;
    Node node1(5), node2(6), node3(2), node4(4);
    Node node5(3, vector<Node*>{&node1, &node2});
    Node root(1, vector<Node*>{&node5, &node3, &node4});
    auto rst = s.levelOrder(&root);
    for (const auto& line : rst) {
        for (const auto& val : line) {
            cout << val << ",";
        }
        cout << endl;
    }
    return 0;
}