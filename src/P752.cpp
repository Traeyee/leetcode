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
    vector<string> get_possibilities(const string& s1) {
        vector<string> rst;

        for (size_t i = 0; i < s1.size(); i++) {
            char c1 = s1[i];
            int ord = c1 - '0';
            char c2 = (ord - 1 + 10) % 10 + '0';
            string s2;
            s2 += s1.substr(0, i);
            s2.push_back(c2);
            s2 += s1.substr(i + 1, s1.size() - 1 - i);
            rst.emplace_back(s2);

            c2 = (ord + 1 + 10) % 10 + '0';
            s2.clear();
            s2 += s1.substr(0, i);
            s2.push_back(c2);
            s2 += s1.substr(i + 1, s1.size() - 1 - i);
            rst.emplace_back(s2);
        }
        return rst;
    }

    int openLock(vector<string>& deadends, string target) {
        if (deadends.end() != find(deadends.begin(), deadends.end(), "0000")) {
            return -1;
        }
        if ("0000" == target) {
            return 0;
        }

        unordered_set<string> deadend_set;
        for (const auto& ele : deadends) {
            deadend_set.insert(ele);
        }

        queue<pair<string, int>> bfs_q;
        bfs_q.push(make_pair("0000", 0));
        unordered_set<string> trials = {"0000"};
        while (!bfs_q.empty()) {
            auto& p = bfs_q.front();
            int turns = p.second;
            turns++;
            const auto& possibilites = get_possibilities(p.first);
            for (const auto& possibility : possibilites) {
                if (deadend_set.end() == deadend_set.find(possibility) &&
                    trials.end() == trials.find(possibility)) {
                    // cout << possibility << endl;
                    if (possibility == target) {
                        return turns;
                    }
                    trials.insert(possibility);
                    bfs_q.push(make_pair(possibility, turns));
                }
            }

            // 切记，引用取front时必须最后才pop销毁，不然会导致使用freed内存
            bfs_q.pop();
        }

        return -1;
    }
};

int main() {
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    Solution s;
    cout << s.openLock(deadends, target);
    return 0;
}