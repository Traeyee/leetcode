/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-18 14:32
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

class Solution {
   public:
    bool is_palindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    string hash_partition(vector<string> ps) {
        stringstream ss;
        for (const auto& s : ps) {
            ss << s << "-";
        }
        return ss.str();
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<string> res0;
        for (int i = 0; i < n; i++) {
            res0.emplace_back(s.substr(i, 1));
        }
        vector<vector<string>> res;
        queue<vector<string>> q;
        q.emplace(res0);
        unordered_set<string> hashes = {hash_partition(res0)};

        while (q.size() > 0) {
            auto& rst = q.front();

            for (int i = 0; i < rst.size() - 1; i++) {
                string s1 = rst[i] + rst[i + 1];
                if (is_palindrome(s1)) {
                    vector<string> res2(rst.begin(), rst.begin() + i);
                    res2.emplace_back(s1);
                    if (i + 2 < n) {
                        res2.insert(res2.end(), rst.begin() + i + 2, rst.end());
                    }
                    string res_hash = hash_partition(res2);
                    if (hashes.end() != hashes.find(res_hash)) {
                        continue;
                    }
                    q.emplace(res2);
                    hashes.insert(res_hash);
                }
            }
            for (int i = 1; i < rst.size() - 1; i++) {
                string s1 = rst[i - 1] + rst[i] + rst[i + 1];
                if (is_palindrome(s1)) {
                    vector<string> res2(rst.begin(), rst.begin() + i - 1);
                    res2.emplace_back(s1);
                    if (i + 2 < n) {
                        res2.insert(res2.end(), rst.begin() + i + 2, rst.end());
                    }
                    string res_hash = hash_partition(res2);
                    if (hashes.end() != hashes.find(res_hash)) {
                        continue;
                    }
                    q.emplace(res2);
                    hashes.insert(res_hash);
                }
            }

            res.emplace_back(rst);
            q.pop();
        }

        return res;
    }
};

void print_partitions(vector<vector<string>>& partitions) {
    for (const auto& partition : partitions) {
        for (const auto& s : partition) {
            cout << s << ", ";
        }
        cout << "\n";
    }
}

int main() {
    Solution sol;
    string s;
    vector<vector<string>> partitions;

    // s = "efe";
    // partitions = sol.partition(s);
    // print_partitions(partitions);

    // s = "abbab";
    // partitions = sol.partition(s);
    // print_partitions(partitions);

    s = "aaabaa";
    partitions = sol.partition(s);
    print_partitions(partitions);

    return 0;
}