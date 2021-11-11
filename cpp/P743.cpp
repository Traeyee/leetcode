#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int adj[n + 1][n + 1];
        int dist[n + 1];
        for (size_t i = 0; i <= n; i++) {
            for (size_t j = 0; j <= n; j++) {
                adj[i][j] = -1;
            }
            dist[i] = 0x3f3f;
        }
        dist[k] = 0;

        for (const auto& time : times) {
            adj[time[0]][time[1]] = time[2];
        }

        unordered_set<int> visited;
        queue<int> node_q;
        node_q.push(k);
        while (node_q.size() > 0) {
            int node = node_q.front();
            visited.insert(node);

            for (size_t i = 1; i <= n; i++) {
                if (node == i) {
                    continue;
                }
                // if (visited.end() != visited.find(i)) {
                //     continue;
                // }
                if (adj[node][i] < 0) {
                    continue;
                }

                int d = dist[node] + adj[node][i];
                // cout << "#" << node << "->" << i << ":" << d << "\n";
                if (d < dist[i]) {
                    dist[i] = d;
                    node_q.push(i);
                }
            }

            node_q.pop();
        }

        if (visited.size() < n) {
            return -1;
        }

        int max_d = 0;
        for (size_t i = 1; i <= n; i++) {
            if (dist[i] > max_d) {
                max_d = dist[i];
            }
        }
        return max_d;
    }
};