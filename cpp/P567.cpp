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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_counter;
        for (const auto& c : s1) {
            s1_counter[c]++;
        }

        int l = 0, r = 0;  // 皆实点
        int valid = 0;
        unordered_map<char, int> s2_counter;
        // 教训：int只能在正数时才能和size_t比较
        while (r < s2.size()) {
            // 假设从上一个invalid开始
            char c = s2[r];
            if (s1_counter.end() != s1_counter.find(c)) {
                s2_counter[c]++;
                if (s1_counter[c] == s2_counter[c]) {
                    valid++;
                }
            }
            r++;

            // cout << s2.substr(l, r - l) << "\n";
            // for (const auto& tmp : s1_counter) {
            //     cout << tmp.first << "," << tmp.second << ";"
            //          << s2_counter[tmp.first] << "\n";
            // }
            if (r - l <= s1.size()) {
                if (valid == s1_counter.size()) {
                    return true;
                }
                continue;
            }

            c = s2[l];
            if (s1_counter.end() != s1_counter.find(c)) {
                if (s1_counter[c] == s2_counter[c]) {
                    valid--;
                }
                s2_counter[c]--;
            }
            l++;

            // cout << s2.substr(l, r - l + 1) << "\n";
            // for (const auto& tmp : s1_counter) {
            //     cout << tmp.first << "," << tmp.second << ";"
            //          << s2_counter[tmp.first] << "\n";
            // }
            if (valid == s1_counter.size()) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    cout << s.checkInclusion("ab", "eidbaooo") << "\n";
    cout << s.checkInclusion("ab", "eidboaoo") << "\n";
    cout << s.checkInclusion("a", "ab") << "\n";

    return 0;
}