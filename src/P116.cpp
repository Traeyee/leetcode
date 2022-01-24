#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));

        int last_depth = 0;
        Node* last_node = new Node;
        while (q.size() > 0) {
            auto& p = q.front();
            auto& node = p.first;
            if (!node) {
                q.pop();
                continue;
            }

            auto& depth = p.second;
            if (depth == last_depth) {
                last_node->next = node;
            } else {
                last_node->next = NULL;
            }
            last_node = node;
            last_depth = depth;
            q.push(make_pair(node->left, depth + 1));
            q.push(make_pair(node->right, depth + 1));

            q.pop();
        }

        return root;
    }
};