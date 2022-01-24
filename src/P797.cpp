/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-10-30 21:41
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    void traverse(vector<vector<int>>& graph, vector<int>& path, int node,
                  vector<vector<int>>& res) {
        path.emplace_back(node);
        int n = graph.size();
        if (n - 1 == node) {
            res.push_back(path);
        }
        for (const auto& next_node : graph[node]) {
            traverse(graph, path, next_node, res);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> res;
        traverse(graph, path, 0, res);
        return res;
    }
};