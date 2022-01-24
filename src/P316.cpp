/**
 * @author cuiyiwork@foxmail.com
 * @time   2022-01-10 10:43
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

class Solution {
   public:
    void _removeDuplicateLetters(string& s, int idx, string& min_res,
                                 string& cur_res, vector<bool>& used) {
        int n = s.size();
        // cout << min_res << ", " << cur_res << '\n';
        if (min_res.size() > 0 && min_res.size() >= cur_res.size() &&
            cur_res > min_res) {
            return;
        }
        if (cur_res.size() >= min_res.size()) {
            min_res = cur_res;
        }

        // 跳过非法idx
        if (idx == n) {
            return;
        }
        int letter_idx = s[idx] - 'a';
        while (used[letter_idx]) {
            idx++;
            if (idx == n) {
                break;
            }
            letter_idx = s[idx] - 'a';
        }
        if (idx == n) {
            return;
        }

        used[letter_idx] = true;
        cur_res.push_back(s[idx]);
        _removeDuplicateLetters(s, idx + 1, min_res, cur_res, used);
        cur_res.pop_back();
        used[letter_idx] = false;

        _removeDuplicateLetters(s, idx + 1, min_res, cur_res, used);
    }
    string removeDuplicateLetters(string s) {
        string max_res, cur_res;
        vector<bool> used(26, false);
        _removeDuplicateLetters(s, 0, max_res, cur_res, used);
        return max_res;
    }
};

int main() {
    Solution sol;
    string s;

    s = "bcabc";
    cout << sol.removeDuplicateLetters(s) << '\n';

    s = "cbacdcbc";
    cout << sol.removeDuplicateLetters(s) << '\n';

    s = "mitnlruhznjfyzmtmfnstsxwktxlboxutbic";
    cout << sol.removeDuplicateLetters(s) << '\n';

    return 0;
}