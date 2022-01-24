// unordered_map 就是哈希表（字典），它的一个方法 count(key) 相当于 Java 的
// containsKey(key) 可以判断键 key 是否存在。 可以使用方括号访问键对应的值
// map[key]。需要注意的是，如果该 key 不存在，C++ 会自动创建这个 key，并把
// map[key] 赋值为 0。
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
    string minWindow(string s, string t) {
        unordered_map<char, int> t_counter;
        for (const auto& c : t) {
            if (t_counter.end() == t_counter.find(c)) {
                t_counter[c] = 0;
            }
            t_counter[c]++;
        }

        vector<pair<int, char>> target_chars;
        for (size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            if (t_counter.end() != t_counter.find(c)) {
                target_chars.emplace_back(make_pair(i, c));
            }
        }

        pair<int, int> min_window = {-1, -1};

        int l = 0, r = t.size() - 1;
        while (r < target_chars.size()) {
            unordered_map<char, int> tmp_counter;
            // 多了个for循环，略慢，通不过leetcode
            for (const auto& p : t_counter) {
                tmp_counter[p.first] = 0;
            }

            for (size_t i = l; i <= r; i++) {
                tmp_counter[target_chars[i].second]++;
            }

            bool pass = true;
            for (const auto& p : tmp_counter) {
                if (p.second < t_counter[p.first]) {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                auto window =
                    make_pair(target_chars[l].first, target_chars[r].first);
                if (-1 == min_window.first) {
                    min_window = window;
                } else if (window.second - window.first <
                           min_window.second - min_window.first) {
                    min_window = window;
                }
            }

            // 滑动
            if (r >= target_chars.size() - 1) {
                l++;
                r = l + t.size() - 1;
            } else {
                r++;
            }
        }

        if (-1 == min_window.first) {
            return "";
        }
        return s.substr(min_window.first,
                        min_window.second - min_window.first + 1);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution s1;
    cout << s1.minWindow(s, t) << endl;

    s = "a", t = "a";
    cout << s1.minWindow(s, t) << endl;

    s = "a", t = "aa";
    cout << s1.minWindow(s, t) << endl;

    s = "cwirwjbfntstplnenpabdttnbiagcnrglbyhnbnavhvmtlqgaqkdmdtnltvpipwuquddvs"
        "eqabctmsbmllsxrlmegjupyqlpmqsjlyalaegozjbkxtjogxsmgodhgqwsjqeureftknhl"
        "wixvdgjjfeyoudvburvdjzxafetqtbdplblrjwcpccdxgyyarvfaxcbciwubzysnzfekei"
        "zgledredrvzyyyazakxvlxvfkwlqgpyixjmbargtohrmftngfldskyywwlmccmkzwzaysh"
        "ugontwhicovfhffhbdsphucutatwalfutviorrxvhscoyhvbmntujvofxjbxwispdcexvd"
        "scvvtveozresnnpbsmmvjifdxlhdicgchexazcqavusikhlevxaffhkessicwqffuchugy"
        "udspncwahuxjzeslll";
    t = "ftpejujeztahrwljlao";
    cout << s1.minWindow(s, t) << endl;

    return 0;
}