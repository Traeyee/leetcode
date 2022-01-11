/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-08 22:59
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

struct UnionFind {
    int size;
    vector<int> parent, tree_size;
    UnionFind(int n) : size(n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            tree_size.push_back(1);
        }
    }
    int find(int p) {
        int p1 = p;
        while (p1 != parent[p1]) {
            parent[p1] = parent[parent[p1]];
            p1 = parent[p1];
        }
        return p1;
    }
    void connect(int p, int q) {
        int root_p = find(p), root_q = find(q);
        if (root_p != root_q) {
            parent[root_p] = root_q;
            tree_size[root_q] += tree_size[root_p];
        }
    }
    int get_union_size(int p) { return tree_size[find(p)]; }
};

class Solution {
   public:
    // 过了，好像TM还不算慢
    int longestConsecutive_unionfind(vector<int>& nums) {
        // 编号
        int n = nums.size();
        map<int, int> idx_map;
        for (int i = 0; i < n; i++) {
            idx_map[nums[i]] = i;
        }
        UnionFind uf(n);
        for (int x : nums) {
            if (idx_map.count(x - 1)) {
                uf.connect(idx_map[x - 1], idx_map[x]);
            }
            if (idx_map.count(x + 1)) {
                uf.connect(idx_map[x + 1], idx_map[x]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int size = uf.get_union_size(i);
            res = size > res ? size : res;
        }
        return res;
    }
    int longestConsecutive_hash(vector<int>& nums) {
        set<int> record(nums.begin(), nums.end());
        set<int> calced;
        int res = 0;
        for (int x : nums) {
            if (!record.count(x - 1) && !calced.count(x)) {
                calced.insert(x);
                int cnt = 1;
                int x1 = x + 1;
                while (record.count(x1)) {
                    cnt++;
                    x1++;
                }
                res = cnt > res ? cnt : res;
            }
        }
        return res;
    }
    int longestConsecutive(vector<int>& nums) {
        return longestConsecutive_unionfind(nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << '\n';

    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(nums) << '\n';

    return 0;
}