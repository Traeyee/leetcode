/**
 * @author cuiyiwork@foxmail.com
 * @time   2021-11-18 14:32
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
    bool can_concat(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        for (int i = 0, j = s2.size() - 1; i < s1.size(); i++, j--) {
            if (s1[i] != s2[j]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> dp(
        string s, int l, int r,
        map<int, map<int, vector<vector<string>>>>& memo) {
        if (memo.end() != memo.find(l) && memo[l].end() != memo[l].find(r)) {
            return memo[l][r];
        }

        vector<vector<string>> res;
        if (l == r) {
            vector<string> sub_res1 = {s.substr(l, 1)};
            res.emplace_back(sub_res1);
        }
        cout << "# " << l << ", " << r << '\n';
        for (int i = l; i < r; i++) {
            auto l_part = dp(s, l, i, memo);
            auto r_part = dp(s, i + 1, r, memo);
            for (const auto& sub_l : l_part) {
                for (const auto& sub_r : r_part) {
                    vector<string> sub_res(sub_l.begin(), sub_l.end());
                    sub_res.insert(sub_res.end(), sub_r.begin(), sub_r.end());
                    res.emplace_back(sub_res);
                    // if (sub_l.size() == 1 && sub_r.size() == 1) {
                    //     if (can_concat(sub_l[0], sub_r[0])) {
                    //         vector<string> sub_res1 = {sub_l[0] + sub_r[0]};
                    //         res.emplace_back(sub_res1);
                    //     }
                    // }
                }
            }
        }

        if (memo.end() == memo.find(l)) {
            memo[l] = map<int, vector<vector<string>>>();
        }
        memo[l][r] = res;
        return res;
    }
    vector<vector<string>> partition(string s) {
        if (0 == s.size()) {
            return {};
        }
        map<int, map<int, vector<vector<string>>>> memo;
        return dp(s, 0, s.size() - 1, memo);
    }

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

    vector<vector<string>> partition__FALSE(string s) {
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