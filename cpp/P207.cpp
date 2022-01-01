/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-18 23:29
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<bool> out(numCourses, false);
        vector<vector<bool>> adj(numCourses, vector<bool>(numCourses, false));

        for (const auto& v : prerequisites) {
            adj[v[0]][v[1]] = true;
            indegree[v[1]]++;
        }

        bool all_zero_indegree = true, changed = true;
        while (changed) {
            all_zero_indegree = true, changed = false;
            for (int v = 0; v < numCourses; v++) {
                if (0 == indegree[v]) {
                    if (!out[v]) {
                        // do something
                        changed = true;
                        out[v] = true;
                        for (int v2 = 0; v2 < numCourses; v2++) {
                            if (adj[v][v2] && !out[v2]) {
                                indegree[v2]--;
                            }
                        }
                    }
                } else {
                    all_zero_indegree = false;
                }
            }
        }

        return all_zero_indegree;
    }
    
    bool canFinish__TL(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> adj(numCourses, vector<bool>(numCourses, false));
        map<int, set<int>> do_map, tmp_do_map;
        for (const auto& v : prerequisites) {
            adj[v[0]][v[1]] = true;
            if (do_map.end() == do_map.find(v[0])) {
                do_map[v[0]] = set<int>();
            }
            do_map[v[0]].insert(v[1]);
        }

        while (do_map.size() > 0) {
            for (const auto& p : do_map) {
                int v = p.first;
                auto& set1 = p.second;
                for (int i = 0; i < numCourses; i++) {
                    if (adj[i][v]) {
                        for (int v1 : set1) {
                            if (i == v1) {
                                return false;
                            }
                            if (!adj[i][v1]) {
                                adj[i][v1] = true;
                                if (tmp_do_map.end() == tmp_do_map.find(i)) {
                                    tmp_do_map[i] = set<int>();
                                }
                                tmp_do_map[i].insert(v1);
                            }
                        }
                    }
                }
            }
            do_map = tmp_do_map;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int numCourses;
    vector<vector<int>> prerequisites;

    numCourses = 2, prerequisites = {{1, 0}};
    cout << sol.canFinish(numCourses, prerequisites) << '\n';

    numCourses = 2, prerequisites = {{1, 0}, {0, 1}};
    cout << sol.canFinish(numCourses, prerequisites) << '\n';

    return 0;
}