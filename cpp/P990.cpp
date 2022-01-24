/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-12-19 22:45
 * @brief
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
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

struct Union {
    vector<int> parent_;

    Union(int n) {
        parent_ = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent_[i] = i;
        }
    }

    int find(int p) {
        int p1 = p;
        while (parent_[p1] != p1) {
            parent_[p1] = parent_[parent_[p1]];
            p1 = parent_[p1];
        }
        return p1;
    }
    void connect(int p, int q) {
        int p_root = find(p);
        int q_root = find(q);
        parent_[p_root] = q_root;
    }
    bool connected(int p, int q) {
        int p_root = find(p);
        int q_root = find(q);
        return p_root == q_root;
    }
};

class Solution {
   public:
    bool equationsPossible(vector<string>& equations) {
        Union union1(26);
        for (const auto& equ : equations) {
            if ('=' == equ[1]) {
                union1.connect(equ[0] - 'a', equ[3] - 'a');
            }
        }

        for (const auto& equ : equations) {
            if ('!' == equ[1]) {
                if (union1.connected(equ[0] - 'a', equ[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<string> equations;

    // equations = {"a==b", "b!=a"};
    // cout << sol.equationsPossible(equations) << '\n';

    // equations = {"b==a", "a==b"};
    // cout << sol.equationsPossible(equations) << '\n';

    // equations = {"a==b", "b==c", "a==c"};
    // cout << sol.equationsPossible(equations) << '\n';

    // equations = {"a==b", "b!=c", "c==a"};
    // cout << sol.equationsPossible(equations) << '\n';

    // equations = {"c==c", "b==d", "x!=z"};
    // cout << sol.equationsPossible(equations) << '\n';

    equations = {"f==a", "a==b", "f!=e", "a==c", "b==e", "c==f"};
    cout << sol.equationsPossible(equations) << '\n';

    return 0;
}